# Exercise 5


## Function-Value Table
Create a library with a function **printFunctionTable** that takes an `ostream&`, a beginning and end value of type `double`, a number of steps, and a function on double as arguments. The function will produce a table of function values as follows by dividing the range given into `n` steps and prints the function results as follows:
(start=1.0, end=3.0, steps=3, f(x) = [](double x){return x*x;})

Expected Output:
```
x    1.0 2.0 3.0  
f(x) 1.0 4.0 9.0
```
You store the `n` used `x` values in a `std::vector<double>` first, by using the algorithm `std::generate_n`.

Demonstrate your function beyond your unit tests by a `main()` function that displays the functions `std::sin(x)`, `std::cos(x)`, `std::tan(x)` for x from `0` to `pi` in `19` steps (10 degrees each).

