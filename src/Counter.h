#ifndef Counter_H_
#define Counter_H_

#include <ostream>




namespace first {
struct Counter{
  int theCount{};
};
inline
void increment(Counter &c){
  ++c.theCount;
}
inline
void print(std::ostream &out, Counter const c) {
  out << c.theCount;
}
}







namespace second {
struct Counter {
  int theCount { };
  void increment() & {
    ++theCount;
  }
  void print(std::ostream &out) const {
    out << theCount;
  }
};
}

namespace third {
struct Counter {
  explicit constexpr
  Counter(int const initial = 0)
  : theCount{initial} { }
  void increment() & {
    ++theCount;
  }
  void print(std::ostream &out) const {
    out << theCount;
  }
#if __cplusplus >= 202000
  constexpr
  bool operator==(Counter const &other) const = default;
#else
  constexpr friend bool
  operator==(Counter const &left, Counter const &right) {
    return left.theCount == right.theCount;
  }
  constexpr friend bool
  operator !=(Counter const &left, Counter const &right) {
    return !(left == right);
  }
#endif
private:
  int theCount { };
};

}

namespace fourth {
struct Counter {
  explicit constexpr
  Counter(int const initial = 0)
  : theCount{initial}{}
  Counter& operator++() & { // ++c
    ++theCount;
    return *this;
  }
  Counter operator++(int) & { // c++
    Counter result{*this}; // save
    ++ *this; // delegate to prefix
    return result;
  }
  friend
  std::ostream& operator<<(std::ostream &out, Counter const&c) {
    return out << c.theCount;
  }
#if __cplusplus >= 202000
  constexpr
  bool operator==(Counter const &other) const = default;
#else
  constexpr friend bool
  operator==(Counter const &left, Counter const &right) {
    return left.theCount == right.theCount;
  }
  constexpr friend bool
  operator !=(Counter const &left, Counter const &right) {
    return !(left == right); // delegate to ==
  }
#endif
private:
  int theCount { };
};

}


namespace IntPair{
  
class IntPair {
  int first{};
  int second{};
public:
  IntPair(int f, int s)
  : first{f}
  , second{s}
  { }
};
  
}

namespace fifth {
struct Counter {
  explicit constexpr
  Counter(int const initial)
  : theCount{initial}{}
  constexpr
  Counter() = default;
  Counter& operator++() & { // ++c
    ++theCount;
    return *this;
  }
  Counter operator++(int) & { // c++
    Counter result{*this};
    ++ *this;
    return result;
  }
  friend
  std::ostream& operator<<(std::ostream &out, Counter const & c) {
    return out << c.theCount;
  }
#if __cplusplus >= 202000
  constexpr
  bool operator==(Counter const &other) const = default;
  constexpr
  auto operator<=>(Counter const &other) const = default;
#else
  constexpr friend bool
  operator==(Counter const &left, Counter const &right) {
    return left.theCount == right.theCount;
  }
  constexpr friend bool
  operator !=(Counter const &left, Counter const &right) {
    return !(left == right);
  }



  constexpr friend bool
  operator<(Counter const &left, Counter const &right) {
    return left.theCount < right.theCount;
  }
  constexpr friend bool
  operator>=(Counter const &left, Counter const &right) {
    return !(left < right);
  }
  constexpr friend bool
  operator>(Counter const &left, Counter const &right) {
    return (right < left);
  }
  constexpr friend bool
  operator<=(Counter const &left, Counter const &right) {
    return !(right < left);
  }

#endif
  protected: // allow subclass extension
  int theCount { };
};









struct DecrementableCounter : Counter {
  using Counter::Counter; // inherit ctors
  Counter& operator--() & { // --c
    --theCount;
    return *this;
  }
  Counter operator--(int) & { // c--
    Counter result{*this}; // save result
    -- *this; // delegate to prefix
    return result;
  }
};

}





#include <iosfwd>
namespace second_separate_impl {
struct Counter {
  int theCount { };
  void increment() &;
  void print(std::ostream &out) const;
};
}



#endif
