#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"
#include <sstream>
#include <stdexcept>


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

struct BoardElement {
  virtual bool canPass() const =0;
  virtual void passElement(Pacman &) &{}
  virtual ~BoardElement() = default;
  BoardElement& operator=(BoardElement&&) & noexcept = delete;
  // Rule of DesDeMova prevents slicing
};
struct Wall : BoardElement {
  bool canPass() const { return false; }
  void passElement(Pacman &) & {
    throw std::logic_error{"cannot pass walls"};
  }
};
struct Pellet : BoardElement {
  bool canPass() const { return true; }
  void passElement(Pacman &p) & { p.eat(*this); }
};
struct Empty : BoardElement {
  bool canPass() const { return true;  }
};
struct PowerPellet : BoardElement {
  bool canPass() const { return true; }
  void passElement(Pacman&p) & { p.eat(*this);  }
};
struct Door : BoardElement {
  bool canPass() const { return true; }
  void passElement(Pacman&p) & { p.warp(*this);  }
};
bool canPass(BoardElement const be){
  return be.canPass();
}
void passElement(Pacman &pacman, BoardElement &be){
  be.passElement(pacman);
}


void testCanPassWallIsFalse() {
  auto const wall{Wall{}};
  ASSERTM("should not pass Wall", not canPass(wall));
}
void testCanPassEmpty() {
  auto const empty{Empty{}};
  ASSERTM("should pass Empty", canPass(empty));
}
void testCanPassPellet() {
  auto const pellet{Pellet{}};
  ASSERTM("should pass Empty", canPass(pellet));
}
void testCanPassPowerPellet() {
  auto const power{PowerPellet{}};
  ASSERTM("should pass Empty", canPass(power));
}

void testPacmanEatsPellet(){
  std::ostringstream out{};
  Pacman pac{out};
  auto be{Pellet{}};
  passElement(pac,be);
  ASSERT_EQUAL("ate pellet\n",out.str());
}
void testPacmanEatsPowerPellet(){
  std::ostringstream out{};
  Pacman pac{out};
  auto be{PowerPellet{}};
  passElement(pac,be);
  ASSERT_EQUAL("ate power\n",out.str());
}

void testPacmanWarpsThroughDoor(){
  std::ostringstream out{};
  Pacman pac{out};
  auto be{Door{}};
  passElement(pac,be);
  ASSERT_EQUAL("warped through door\n",out.str());
}
void testPacmanPassesEmpty(){
  std::ostringstream out{};
  Pacman pac{out};
  auto be{Empty{}};
  passElement(pac,be);
  ASSERT_EQUAL("",out.str());
}
void testPacmanWillnotTryPassingWalls(){
  std::ostringstream out{};
  Pacman pac{out};
  auto be{Wall{}};
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
