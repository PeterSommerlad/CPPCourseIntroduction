#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"
#include <variant>
#include <array>
#include <sstream>
#include <stdexcept>

// variant helper:
template<class... Ts> struct overloaded : Ts... { using Ts::operator()...; };
// explicit deduction guide (not needed as of C++20)
template<class... Ts> overloaded(Ts...) -> overloaded<Ts...>;

// Pacman Board Elements

struct Pellet;
struct PowerPellet;
struct Door;

struct Pacman{
  explicit Pacman(std::ostream &out):out{out}{}
  void eat(Pellet const&) &;
  void eat(PowerPellet const&) &;
  void warp(Door const&) &;
  std::ostream &out;
};

struct Wall{
  bool canPass() const { return false; }
};
struct Empty{
  bool canPass() const { return true;  }
};
struct Pellet{
  bool canPass() const { return true; }
  void consumed(Pacman &p) { p.eat(*this); }
};
struct PowerPellet{
  bool canPass() const { return true; }
    void powerup(Pacman&p) { p.eat(*this);  }
};
struct Door{
  bool canPass() const { return true; }
  void passThrough(Pacman&p) { p.warp(*this);  }
};



using BoardElement=std::variant<Empty,Wall,Door,Pellet,PowerPellet>;
bool canPass(BoardElement be){
  return std::visit([](auto elt){
    return elt.canPass();
  }, be); // dynamic delegation to type
}
void passElement(Pacman &pacman, BoardElement be){
  std::visit(overloaded{
    [](auto){FAILM("not a visited element");},
    //[](Wall){ throw std::logic_error{"cannot pass through walls"} ;},
    [](Empty){/* nothing */},
    [&pacman](Door d){ d.passThrough(pacman);},
    [&pacman](Pellet p){ p.consumed(pacman);},
    [&pacman](PowerPellet p){ p.powerup(pacman);}
  },be); // type-based "switch"
}
using Board = std::array<std::array<BoardElement,28>,31>;


void testCanPassWallIsFalse() {
  BoardElement const wall{Wall{}};
  ASSERTM("should not pass Wall", not canPass(wall));
}
void testCanPassEmpty() {
  BoardElement const empty{Empty{}};
  ASSERTM("should pass Empty", canPass(empty));
}
void testCanPassPellet() {
  BoardElement const pellet{Pellet{}};
  ASSERTM("should pass Empty", canPass(pellet));
}
void testCanPassPowerPellet() {
  BoardElement const power{PowerPellet{}};
  ASSERTM("should pass Empty", canPass(power));
}

void testPacmanEatsPellet(){
  std::ostringstream out{};
  Pacman pac{out};
  BoardElement be{Pellet{}};
  passElement(pac,be);
  ASSERT_EQUAL("ate pellet\n",out.str());
}
void testPacmanEatsPowerPellet(){
  std::ostringstream out{};
  Pacman pac{out};
  BoardElement be{PowerPellet{}};
  passElement(pac,be);
  ASSERT_EQUAL("ate power\n",out.str());
}

void testPacmanWarpsThroughDoor(){
  std::ostringstream out{};
  Pacman pac{out};
  BoardElement be{Door{}};
  passElement(pac,be);
  ASSERT_EQUAL("warped through door\n",out.str());
}
void testPacmanPassesEmpty(){
  std::ostringstream out{};
  Pacman pac{out};
  BoardElement be{Empty{}};
  passElement(pac,be);
  ASSERT_EQUAL("",out.str());
}
void testPacmanWillnotTryPassingWalls(){
  std::ostringstream out{};
  Pacman pac{out};
  BoardElement be{Wall{}};
  ASSERT_THROWS(passElement(pac,be),std::logic_error);
}




bool runAllTests(int argc, char const *argv[]) {
  cute::suite s { };
  //TODO add your test here
  s.push_back(CUTE(testCanPassWallIsFalse));
  s.push_back(CUTE(testCanPassEmpty));
  s.push_back(CUTE(testCanPassPellet));
  s.push_back(CUTE(testCanPassPowerPellet));
  s.push_back(CUTE(testPacmanEatsPellet));
  s.push_back(CUTE(testPacmanEatsPowerPellet));
  s.push_back(CUTE(testPacmanWarpsThroughDoor));
  s.push_back(CUTE(testPacmanPassesEmpty));
  s.push_back(CUTE(testPacmanWillnotTryPassingWalls));
  cute::xml_file_opener xmlfile(argc, argv);
  cute::xml_listener<cute::ide_listener<>> lis(xmlfile.out);
  auto runner = cute::makeRunner(lis, argc, argv);
  bool success = runner(s, "AllTests");
  return success;
}

int main(int argc, char const *argv[]) {
    return runAllTests(argc, argv) ? EXIT_SUCCESS : EXIT_FAILURE;
}

void Pacman::eat(Pellet const&) & {
  out << "ate pellet\n";
}

inline void Pacman::eat(PowerPellet const&) & {
  out << "ate power\n";
}

inline void Pacman::warp(Door const&) & {
    out << "warped through door\n";
}
