# Exercise 5

## a) Word List

Write a program **wlist** that reads all words (as defined by std::string's input operator >>) from the standard input and produce a sorted list of all occurring words, where each word only is printed once. What data structure and algorithms are you using? Do not write your own loops nor use `std::for_each`.

*  Can you ignore the case of letters, so that `Hello == hello` ?
*  Can you ignore non-letter characters from input?


**Hints:**
*  Have a look at functions defined in `<cctype>` (character-type) and the available algorithms in `<algorithm>` (`std::lexicographical_compare`).
*  To implement the functionality with an `std::vector` you might need further algorithms: `sort` and `unique`
 

## b Function-Value Table
Create a library with a function **printFunctionTable** that takes an `ostream&`, a beginning and end value of type `double`, a number of steps, and a function on double as arguments. The function will produce a table of function values as follows by dividing the range given into `n` steps and prints the function results as follows:
(start=1.0, end=3.0, steps=3, f(x) = [](double x){return x*x;})

Expected Output:
```
x    1.0 2.0 3.0  
f(x) 1.0 4.0 9.0
```
You store the `n` used `x` values in a `std::vector<double>` first, by using the algorithm `std::generate_n`.

Demonstrate your function beyond your unit tests by a `main()` function that displays the functions `std::sin(x)`, `std::cos(x)`, `std::tan(x)` for x from `0` to `pi` in `19` steps (10 degrees each).

