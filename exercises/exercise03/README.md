
# Exercise 3. Counting again - without loops

This exercise repeats the problems of the last exercise. However, now you need to solve the task without writing a loop of your own, but by using iterators and algorithms of the standard library. One function you might need to know about is `std::distance()` that takes two iterators forming a range and returns the number of elements in that range. Using distance is convenient for counting all elements in a range.

If you are unsure about the correct solution, start out with encapsulating it in a function and write unit tests first using `std::stringstream` objects as input and output substitutes. Create all solutions by using algorithms instead of loops. If you can not achieve that, please ask your supervisor for tips.

**Hints:**

  - Like in the previous exercises start with a CUTE Project and implement the functions and tests directly in the `Test.cpp` file. Afterwards, when you are happy with your code you can separate the tests and the implementation as described above. 


## a) charc: Count non-whitespace char
 
Write a function `charc()` to count non-whitespace char values by reading from an input stream (`std::istream)`). The result should be the number of characters found in the stream.

```cpp
unsigned charc(std::istream & input) {
  //Your implementation of charc
}
```

## b) allcharc: Count all characters
 
Create a function `allcharc()` with the same signature as `charc()`. The `allcharc()` function must not skip white-space characters when counting.

**Hints:**

  -  You need to use the stream iterator that does not skip whitespace characters to achieve that.


## c) wc: Count words
 
Write a function `wc()`, calling it to count words separated by white space character by reading from a given `std::istream`. The result should be the number of words found in the stream. Use an iterator and `std::distance()` to calculate the result.

A word should be defined by what the input operator (`>>`) decides to be read as a `std::string`.

## d) lc: Count lines
 
Write a function `lc()` to count the lines by reading from an istream.

After checking its functionality using some unit tests, use that function in a program **lcount** that counts the number of lines available on standard input. The result should be printed on standard output. Compare your output with the result of the _wc -l_ command on a large text file.

<hr/>


# e) Word List with `std::string`

Write a program **wlist** that reads all words (as defined by std::string's input operator >>) from the standard input and produce a sorted list of all occurring words, where each word only is printed once. What data structure and algorithms are you using? Do not write your own loops nor use `std::for_each`.

* e1) Can you ignore the case of letters, so that `Hello == hello` ?
* e2) Can you ignore non-letter characters from input?


**Hints:**
*  Have a look at functions defined in `<cctype>` (character-type) and the available algorithms in `<algorithm>` (`std::lexicographical_compare()`).
*  To implement the functionality with an `std::vector` you might need further algorithms: `sort()` and `unique()`
 


# 3. Extra exercises for self-study (Optional)

These relate to exercise2-extra.


## f)  Sum numbers

Write a function **sumi(std::istream&)** to sum up a sequence of integer numbers given on an input stream. Assume only numbers separated by whitespace are given. Return the resulting sum. Do not use a loop. How much would need to change to sum floating point numbers instead? Do so but in a separate function called **sumd(std::istream&)**

## g)  Multiplication table

Write a program **multab** to print a multiplication table for the integers from 1 to 20. Start by filling a `std::vector<int>` with the numbers 1 to 20. You shouldn't use a loop to create the table, therefore you might need to nest algorithm calls in a lambda expression or function call to get the nested iteration. The output can be generated onto an `std::ostream_iterator` with an algorithm that 'transforms' its input.

Note: **use a lambda with capture by reference:**
```
[&](auto x){...}
```

## h) Decimal Fractions

Can you vary your program _multab_ to print a table of decimal fractions (**fractab**) for a divided by b, where a and b take the range from 1 to 10? Also without any self-made loops.

