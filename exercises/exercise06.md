# Exercise 6 - Enumerations

##  a) Simulated Switch with Toggle Button

To exercise an enum type with hidden `enum` values we implement a class `Switch`. The `Switch` simulates three states: `off`, `on`, `blinking`. It comes with a single button simulated with the member function `pressButton()` that switches from `off` to `on` to `blinking` and then to `off` again. Provide an output `operator<<` for both your `Switch` class and your `enum` type, the first delegating to the latter.

The following test case demonstrates the behavior of the Switch class:

```
void testOutputOfSwitch() {
  Switch s{};
  std::ostringstream out{};
  out << s << '\n';
  s.pressButton();
  out << s << '\n';
  s.pressButton();
  out << s << '\n';
  s.pressButton();
  out << s << '\n';
  s.pressButton();
  out << s << '\n';
  ASSERT_EQUAL(
      "off\n"
      "on\n"
      "blinking\n"
      "off\n"
      "on\n", out.str());
}
```

##  b) Optional exercise: Unsigned Short enum Replacement

C++ `unsigned` number types that are "shorter" than `int` are implicitly promoted to `int` before any arithmetic conversion happens. 
Therefore, some safety programming guidelines discourage the use of `unsigned char` and `unsigned short` or `uint8_t` and `uint16_t` respectively.

However, using an enumeration type with a base type of `uint16_t` (see `#include <cstdint>`) we can overload the arithmetic operators in a way, that all operations are done with the type `unsinged` that does not risk undefined behavior on overflow (except for division by zero).

Implement an enumeration type `uint16` with no enumerators in namespace `safeint` together with the arithmetic operators for that type. All operations will result in the result being of type `uint16` and will internally use `static_cast<unsigend>(value)` before delegating to the corresponding built-in operator on that type.

Detect division by zero and throw a `std::logic_error` object from your operator overload.

Provide corresponding test cases (actually start with a testcase before implementing the operator). Don't forget the ability to output or input values of type `uint16`.


A generic solution for this problem for all integer types can be found at [https://github.com/PeterSommerlad/PSsimplesafeint](https://github.com/PeterSommerlad/PSsimplesafeint)

