# Exercise 3. Counting Input Elements
In this exercise you will...

  - implement various character counting algorithms.
  - use the input operator (`>>`) to read different types from `std::istream`.
  - figure out how when the input operator (`>>`) skips white-space characters and how to avoid that skipping.
  - this is a precursor to the next exercise, where we solve these problems without loops.

**Hints:**

  - Please consult your cppreference.com on `iostreams` to figure out which member function to use, if the input operator `>>` doesn’t help with solving the problem. 
  - Like in the previous exercise start with a CUTE Project and implement the functions and tests directly in the `Test.cpp` file. Afterwards, when you are happy with your code you can separate the tests and the implementation as described above. 
  - You should use an `std::istringstream` to provide your input from in test cases.
  - Do not forget to write unit tests for the following cases:
    - How does your functional core behave with empty input? 
    - Do you always get the result you are expecting?
  - Try not to store too much of the input
  - All the counting programs should look quite similar in structure
  - If you experience problems because your program does not terminate properly try to shut down your program using the red box in the Console window it is running within Cevelop
  - It can cause to hang your Cevelop IDE on some of the platforms (Mac). When that happens, you need to kill your own program from a terminal window or task manager/system monitor/activity monitor. This should make Cevelop usable again. If all fails, you might need to restart Cevelop as well


## a) charc: Count non-whitespace char
 
Write a function `charc()` to count non-whitespace char values by reading from an input stream (`std::istream)`). The result should be the number of characters found in the stream.

```cpp
unsigned charc(std::istream & input) {
  //Your implementation of charc
}
```

**Example:** if you call the `charc()` function with a stream containing the characters `Hello, world!`, the function should return `12`.

Please note, that the input `operator >>` always skips white space characters such as blank, tab and newline.

## b) allcharc: Count all characters
 
Create a function `allcharc()` with the same signature as `charc()`. The `allcharc()` function must not skip white-space characters when counting.

**Hints:**

  -  You might need to use a member function of `std::istream` to achieve that.
  -  You should first write test cases for your new function, before implementing the function!


**Question:** Can you find other means (than the member function of `std::istream`) to not skip the white space?

## c) wc: Count words
 
Write a function `wc()`, calling it to count words separated by white space character by reading from a given `std::istream`. The result should be the number of words found in the stream.

A word should be defined by what the input operator (`>>`) decides to be read as a `std::string`.

## d) lc: Count lines
 
Write a function `lc()` to count the lines by reading from standard input.

**Hint:** There are several means to achieve that, for example, count the characters matching the newline character `'\n'`, or, use the `getline()` function and count how often you can call it until you reach the end of the input.

## e) Modularization
 
After you have implemented all functions you can split up the structure as follows:

  - Library project that contains all the implementations of the functions. It contains two files `charcount.cpp` and `charcount.h`
  - A test project for testing the library. It contains the `Test.cpp` file with all CUTE tests. You can also split the test functions into CUTE suites for each function, if you like.
  - An executable project for each feature: `charc()`, `allcharc()`, `wc()` and `lc()`. In each executable project there only exists a `main.cpp` with a simple main that calls the corresponding library function with `std::cin` as argument and prints the result to `std::cout`.


**Note:** Do not write any fancy "UI", so that you can use your programs also as filters within a shell-pipeline.

Compare the result of your function with the size of the file you use as input on the console (e.g., `$ allcharc < file.txt`). You executables should be located in the `Debug` directory of the executable project.

