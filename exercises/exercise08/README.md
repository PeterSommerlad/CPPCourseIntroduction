# Exercise 8: Algorithms

## a) Checking for Palindromes

 A palindrome is a word or sentence that can be read from its beginning and its end and results in the same word (in our example ignore whitespace). For example, the name "Otto" is a palindrome. Write a predicate `is_palindrome(std::string)` taking a string and returning if the string is a palindrome (ignoring letter case).

Use that function to find all palindromes in the [linux words dictionary](https://raw.githubusercontent.com/PeterSommerlad/CPPCourseIntroduction/main/exercises/linuxwords.txt) (or use /usr/share/dict/words)


## b) Word Statistics

Use your class `Word` and create the following simple programs that provide the following results. 

* Remember: your `Word` class ignores case when compared and also ignores punctuation and white space. 
* Don't program your own loops. 
* Use appropriate data structures but don't store data unnecessarily.

Implement the following functions:

* `unsigned wcount(std::istream &)`: Returns the number of words in standard input
* `void nth(std::istream &, std::ostream &, unsigned nth)`: Count words and print out `nth` most frequent. Similar to the `printOccurrences` function in Exercise 7, but only print the nth most frequent word (only a single word). Do not reuse exact code of `printOccurrences`, but again use the most optimal data structure and algorithms for this problem. 


## c) Prime Numbers

Write a program primes that outputs prime numbers. Create a predicate function `isPrime(int)`. 

* Use that predicate to filter a vector filled with numbers from `1` to `100`. 
* Don't write your own loops but use the most fitting algorithms from the standard library (i.e., don't use `for_each()` with a lambda, when there exists a better algorithm.) 
* Can there be a solution for where even `isPrime()` is not using a hand-written loop?

Variants of your program:

* How many prime numbers do you get in the range `1..100`?
* How many in the range `1..1000`?
 



## d) Algorithms Trivia

Use Cevelop to "Import Existing Projects into Workspace" to obtain the project **algorithm_trivia** in the folder src. To allow using it without cloning the repository, you can download [algorithm_trivia.zip](https://github.com/PeterSommerlad/CPPCourseIntroduction/raw/main/src/algorithm_trivia.zip) and unpack it locally. And then import the project in the directory. 

For using the existing STL algorithms effectively you have to familiarize yourself with available functionality. We have prepared a CUTE test project (`algorithm_trivia`) with a large set of test cases which require you to insert the correct STL algorithm in order to get the test green. It contains several test suites, each containing some test cases. Usually, those cases fail with the current implementation. We have replaced the original calls with dummy functions (`xxx`, `xxxx`, `xxxxx`, `xxxxxx`) that satisfy the interface. You don't have to worry about these helper functions. Your task is to fix the test cases by calling the correct STL algorithm (instead of the helper function).

Since there are quite a few algorithms you don't have to solve all algorithms at one. We suggest to solve 2-3 test suites each week. Each suite contains a hint header that lists the algorithms that have to be used in the corresponding suite file. Each algorithm is required once. Read the description of the algorithms first and then try to insert the correct calls. Some algorithms require a predicate. Most of the time we have used an `is_prime` function that just checks whether the parameter is prime.

Have Fun!



## e) Generating Anagrams

Write a program that reads a word from standard input and creates all possible anagrams (permutations of the letters in the word).

Use a data structure to collect the anagrams that keeps them in sorted order and eliminates duplicates.

On Linux/Mac/Unix you can read in the file /usr/share/dict/words into a data structure and filter your anagrams according to the valid words. Try this with short words first, otherwise generating the permutations might take a long time (factorial(size())).

How many anagrams forming a word according to your system's dictionary do you find for the word "listen" ?

**Extension:** Can you extend your program in a way that it also will check for valid anagrams consisting of multiple words, i.e., `"Vacation time" = "I am not active"` (might be a bit harder and slower). 

**Variation:** Can you find all 5-letter anagrams in the  [Wordle_wordlist](https://raw.githubusercontent.com/PeterSommerlad/CPPCourseIntroduction/main/exercises/Wordle_wordlist) 
that have more than N anagrams in that list, so they are hard to guess (N>=4).

## f) self-study:  KWIC - Keyword in Context

From Parnas [[Parnas72](http://dl.acm.org/citation.cfm?id=361623&coll=ACM&dl=ACM)] we have a concise definition of the Keyword in Context problem:


    The KWIC index system accepts an ordered set of lines, 
    each line is an ordered set of words, 
    and each word is an ordered set of characters. 
    Any line may be "circularly shifted" by repeatedly removing the first word
    and appending it at the end of the line. 
    The KWIC index system outputs a listing of all circular shifts of all lines in alphabetical order. 


**Note:** In the description *ordered set* does not mean a sorted set like the `std::set` but rather a *sequence thereof*. If you lookup the definition in [Wikipedia](https://en.wikipedia.org/wiki/Key_Word_in_Context), you are expected to implement the functionality depicted in the *KWAC* example.

Write a function `kwic` that reads lines from standard input and creates the variations of the line where each word is in front once. Output the stored lines in sorted order, so that you can see, how the words are used in context.

Example input:

```
this is a test
this is another test
```

result:

```
a test this is
another test this is
is a test this
is another test this
test this is a
test this is another
this is a test
this is another test
```

Clarifying example input:

```
a b c d
a a b
b b c
```

result:

```
a a b
a b a
a b c d
b a a
b b c
b c b
b c d a
c b b
c d a b
d a b c
```
 

Tips:

* Use algorithms `rotate` or `rotate_copy` to generate the word lists for each line.
* You must use your `Word` class to be able to ignore punctuation and case of the letters.
* Use the appropriate data structures to achieve the result without unnecessary code or loops.
* In addition to the test of your `Word` class you can also separate your logic into independently testable functions, separate the tests and your `main()` function into distinct IDE projects, relying on the library projects for your `Word` class and KWIC functionality.
* Create an alias for lines (`std::vector<text::Word>`) 


