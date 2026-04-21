
# Exercise 4.

## a) Function-Value Table

Create a library with a function **printFunctionTable** that takes an `ostream&`, a beginning and end value of type `double`, a number of steps, and a function on double as arguments. The function will produce a table of function values as follows by dividing the range given into `n` steps and prints the function results as follows:
(start=1.0, end=3.0, steps=3, f(x) = [](double x){return x*x;})

Expected Output:
```
x    1.0 2.0 3.0  
f(x) 1.0 4.0 9.0
```
You store the `n` used `x` values in a `std::vector<double>` first, by using the algorithm `std::generate_n()`.
For producing the output of the vector use algorithm `copy()` with a `std::ostream_iterator<double>`.
For output with the function application you can use `std::transform()`, which works like `copy()` but applies a function on each element transferred to the output.


Demonstrate your function beyond your unit tests by a `main()` function that displays the functions `std::sin(x)`, `std::cos(x)`, `std::tan(x)` for x from `0` to `pi` in `19` steps (10 degrees each).


## b) attempt top solve the algorithm trivia exercise of exercise08

This exercise helps you explore the space of the standard library algorithsm and can be solved on the extra self-study day.


Use Cevelop to "Import Existing Projects into Workspace" to obtain the project **algorithm_trivia** in the folder src. To allow using it without cloning the repository, you can download [algorithm_trivia.zip](https://github.com/PeterSommerlad/CPPCourseIntroduction/raw/main/src/algorithm_trivia.zip) and unpack it locally. And then import the project in the directory. 

For using the existing STL algorithms effectively you have to familiarize yourself with available functionality. We have prepared a CUTE test project (`algorithm_trivia`) with a large set of test cases which require you to insert the correct STL algorithm in order to get the test green. It contains several test suites, each containing some test cases. Usually, those cases fail with the current implementation. We have replaced the original calls with dummy functions (`xxx`, `xxxx`, `xxxxx`, `xxxxxx`) that satisfy the interface. You don't have to worry about these helper functions. Your task is to fix the test cases by calling the correct STL algorithm (instead of the helper function).

Since there are quite a few algorithms you don't have to solve all algorithms at one. We suggest to solve 2-3 test suites each week. Each suite contains a hint header that lists the algorithms that have to be used in the corresponding suite file. Each algorithm is required once. Read the description of the algorithms first and then try to insert the correct calls. Some algorithms require a predicate. Most of the time we have used an `is_prime` function that just checks whether the parameter is prime.

Have Fun!

A direct link to godbolt compiler explorer is [here](https://godbolt.org/z/vMjhdbWP8). Note, remove "Find Algorithms" to run all trivia tests, or replace it by the name of a test suite as spelled in Test.cpp including the quotes. Sometimes compiler explorer might timeout, change something to try again.


