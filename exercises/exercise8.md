# Exercise 8:  KWIC - Keyword in Context

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
* You must use your `Word` class from week 5 to be able to ignore punctuation and case of the letters.
* Use the appropriate data structures to achieve the result without unnecessary code or loops.
* In addition to the test of your `Word` class you can also separate your logic into independently testable functions, provide the tests and your `main()` function.
* Create an alias for lines (`std::vector<text::Word>`) 


