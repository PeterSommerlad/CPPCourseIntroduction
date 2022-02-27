# Exercise 2 - Simple Calculator

In this exercise you will...

  - implement a function for performing different operations on function parameters and return the result.
  - read formatted input from an `std::istream`
  - split a project containing an implementation and tests into tree projects: `library` (with implementation), `tests` and `executable`. This is a repetition of the modularization you have already performed on the `SayHello` project.



## a) Implement a `calc` function

Create a function with the signature `int calc(int, int, char)` that takes two numbers an a character denoting an operator symbol (`'+'`, `'-'`, `'*'`, `'/'` and `'%'`). The function `calc` should interpret the operator character and compute its result by combining the two integers accordingly. To give you a headstart you can use the code below in a CUTE Project as `Test.cpp`. Add additional test cases for the corner cases of the function. Consider and test valid and invalid input, e.g. unknown operators and division by zero. What options for error handling are feasible? Discuss them with your supervisor and your peers.

To start, just use a single CUTE Test Project and develop your code there. In the last part of this exercise you will split the code into different projects.

```cpp
#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"

int calc(int lhs, int rhs, char op) {
  //TODO Implement functionality
  return 0;
}

void test_one_plus_one() {
  auto result = calc(1, 1, '+');
  ASSERT_EQUAL(2, result);
}

//TODO Add more tests here


bool runAllTests(int argc, char const *argv[]) {
  cute::suite s { };
  //TODO Register tests
  s.push_back(CUTE(test_one_plus_one));
  cute::xml_file_opener xmlfile(argc, argv);
  cute::xml_listener<cute::ide_listener<>> lis(xmlfile.out);
  auto runner { cute::makeRunner(lis, argc, argv) };
  bool success = runner(s, "AllTests");
  return success;
}

int main(int argc, char const *argv[]) {
  return runAllTests(argc, argv) ? EXIT_SUCCESS : EXIT_FAILURE;
}
```

Hint for the implementation: Consider using a `switch` statement in the `calc` function.

## b) Extension: Simple calculator with stream input 

Extend your simple calculator from above and create an additional function `int calc(std::istream& in)` that will read a number, an operator character and another number from the `istream` `in` and compute the result of the operation. E.g. `1 + 1` results in `2`. Also provide unit tests for this new calculator. 

When tests for a function taking an `std::istream &` as argument, you have to create an `std::istringstream` that contains the given input.

```cpp
void testCalcWithStream() {
  std::istringstream input{"95/5"};
  auto result = calc(input);
  //...
}
```

## c) Modularization: Separate Projects

You have implemented the complete functionality of the `calc` function in the unit test project. In order to use them in an executable it would be desirable to have them in a separate library. This is best realized stepwise.

  - Separation into new compilation unit (`.cpp` file)
    - Move the `calc` functions to a new source file (`calculator.cpp`) in the test project
    - To be able to use the `calc` functions from the tests in the `Test.cpp` file a header file with the corresponding declarations is required. Create a header file (`calculator.h`) which contains an include guard and the declarations for both functions.
    - Add an include directive for including the `calculator.h` header file to both source files `Test.cpp` and `calculator.cpp`.


Now your test project should compile without errors and run as before. If not figure out why and fix remaining errors. 

  - Separation into distinct projects
    - Create a new Static Library Project
    - Move the files `calculator.h` and `calculator.cpp` to this new project
    - Now we need to tell Cevelop that there is a dependency from the test project to the new library project
      - Open the references of the test project: Right-click on the test project `-> Properties -> C/C++ General -> Paths and Symbols -> References (Tab)`
      - Tick the library project and press apply. This should automatically add the library project to the includes (Includes tab), the library of the library project (`Library` tab) and the library path of the library project (`Library Paths` tab). If those are missing add them manually - ask for assistance if it does not work.


Now your test project should compile without errors and run as before. If not figure out why and fix remaining error. 

  - Executable project 

Now create an executable project with a `main.cpp` source file that contains the following main function. You have to set up the dependencies from the executable project to the library project as well (See steps above). Then you can use your calculator from the console.

```cpp
int main() {
  while (std::cin) {
    std::cout << '=' << calc(std::cin) << '\n';
  }
}
```




