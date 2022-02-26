#include "Counter.h"
#include <ostream>
namespace second_separate_impl {
void Counter::increment() & {
  ++theCount;
}
void Counter::print(std::ostream &out) const {
  out << theCount;
}
}
