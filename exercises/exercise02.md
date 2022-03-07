# Exercise 2. Counting Input Elements

In this exercise you will...

  - implement various character counting algorithms.
  - use the input operator (`>>`) to read different types from `std::istream &`.
  - figure out how when the input operator (`>>`) skips white-space characters and how to avoid that skipping.
  - this is a precursor to the next exercise, where we solve these problems without loops.

**Hints:**

  - Please consult your https://cppreference.com on `iostreams` to figure out which member function to use, if the input operator `>>` doesn’t help with solving the problem. 
  - Start with a CUTE Project and implement the functions and tests directly in the `Test.cpp` file. Afterwards, when you are happy with your code you can separate the tests and the implementation as described below. 
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


**Question:** Can you find other means (than the member function of `std::istream`) to not _skip the white space_ ?

## c) wc: Count words
 
Write a function `wc()`, calling it to count words separated by white space character by reading from a given `std::istream`. The result should be the number of words found in the stream.

A word should be defined by what the input operator (`>>`) decides to be read as a `std::string`.

## d) lc: Count lines
 
Write a function `lc()` to count the lines by reading from standard input.

**Hint:** There are several means to achieve that, for example, count the characters matching the newline character `'\n'`, or, use the `getline()` function and count how often you can call it until you reach the end of the input.

## e) Modularization:  Separate Projects
 
After you have implemented all functions you can split up the structure as follows:

  - Separation into new compilation unit (`.cpp` file)
    - move the functions to a _new source file_ `charcount.cpp` and add the `#include` directives for the standard library parts used.
    - to be able to use the functions from other translation units, create a _new header file_ `counting.h` and declare the functions there. Add the minimal required header `#include` in the header file and don't forget to `#include "charcount.h"` in your source file `charcount.cpp`
  - Create a _New C++ Static Library project_ "charcount" that contains the two files `charcount.cpp` and `charcount.h`
  - Create a _New C++ CUTE project_ test project for testing the library. It contains the `Test.cpp` file with all CUTE tests. You can also split the test functions into CUTE suites for each function, if you like.
  - Now we need to tell Cevelop that there is a dependency from the test project to the new library project
    - Open the references of the test project: Right-click on the test project `-> Properties -> C/C++ General -> Paths and Symbols -> References (Tab)`
    - Tick the library project and press apply. This should automatically add the library project to the includes (Includes tab), the library of the library project (`Library` tab) and the library path of the library project (`Library Paths` tab). If those are missing add them manually - ask for assistance if it does not work.
  - Create a _New C++ executable project_ for **each** feature: `charc()`, `allcharc()`, `wc()` and `lc()`. In each executable project there only exists a `main.cpp` with a simple `main()` function that calls the corresponding library function with `std::cin` as argument and prints the result to `std::cout`.
     - Each of these projects requires the settings to be adapted, so that the compiler settings will have the correct `INCLUDE_PATH` and `LIBRARY_PATH` for the "charcount" library project as well as the library flag (`-lcharcount`)
  


**Note:** Do not write any fancy "UI", so that you can use your programs also as filters within a shell-pipeline.

Compare the result of your function with the size of the file you use as input on the console (e.g., `$ allcharc < file.txt`). You executables should be located in the `Debug` directory of the executable project.


# 2e. Optional exercises  (also for self-study)

## a) Sum numbers
 
Write a program `sumi()` to sum up a sequence of integer numbers given in standard input. Assume only numbers separated by whitespace are given. Print the resulting sum on standard output.

Example: Input `0 55 222 41 11` should result in `329`

Once you are done, change your program to accept floating point numbers instead ('sumf'). How many places do you need to change?


## b) Average numbers
 
Write a program `averagei()` to calculate the average of a sequence of integer numbers given in standard input. Assume only numbers separated by whitespace are provided. Print the resulting average with the number of elements on standard output.

Example: 

```
> averagei
0 55 222 41 11<EOF>
Average: 65.8
Count: 5
```

Once you are done, change your program to accept floating point numbers instead (`averagef()`). How many places do you need to change?


  - **Tip:** you can base this program on your sum numbers program.

## c) Multiplication table (nested loops)
 
Write a program `multab` to print a multiplication table for the integers from `1` to `20`. Make it more flexible, so that one can input the maximum factor up to `30` and create the table up to that factor. Make the table look nice and aligned if printed with a fixed-width font.

Example: 

```
> multab
Enter limit (max 30):5
    1    2    3    4    5
    2    4    6    8   10
    3    6    9   12   15
    4    8   12   16   20
    5   10   15   20   25
```


## d) Decimal Fractions 
 
Can you vary your program `multab` to print a table of decimal fractions (`fractab`) for `a` divided by `b`, where `a` and `b` take the range from `1` to `10`?

Example: 

```
> fractab
enter limit (max 30):6
        0        1        2        3        4        5        6
        1        1      0.5  0.33333     0.25      0.2  0.16667
        2        2        1  0.66667      0.5      0.4  0.33333
        3        3      1.5        1     0.75      0.6      0.5
        4        4        2   1.3333        1      0.8  0.66667
        5        5      2.5   1.6667     1.25        1  0.83333
        6        6        3        2      1.5      1.2        1
```

## e) Bartender cheat sheet (loops)
 
The VSHSR bartender who sells lots of drinks on the semester party might have a few drinks herself. Multiplication of drink prices can thus become a challenge. 

Create a multiplication sheet for the multiples up to `10` times for the following drinks: *small* Beer 4.65, a *Moaß* Beer 9.15, Schnapps 3.85, Soda 2.95. This sheet will help the bartender with her task of asking for the money when one buys a round.


  - Can you make the application configurable, so that there is one place where you can specify a drink and its unit price an generate tables for arbitrary drinks or price changes easily?
  




