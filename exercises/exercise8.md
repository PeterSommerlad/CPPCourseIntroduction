# Exercise 9: Algorithms

## a) Checking for Palindromes

 A palindrome is a word or sentence that can be read from its beginning and its end and results in the same word (in our example ignore whitespace). For example, the name "Otto" is a palindrome. Write a predicate `is_palindrome(std::string)` taking a string and returning if the string is a palindrome (ignoring letter case).

Use that function to find all palindromes in the dictionary file in the exercise templates.

## b) Algorithms Trivia

Use Cevelop to "Import Existing Projects into Workspace" to obtain the project **algorithm_trivia** in the folder src. To allow using it without cloning the repository, you can download [algorithm_trivia.zip](https://github.com/PeterSommerlad/CPPCourseIntroduction/raw/main/src/algorithm_trivia.zip) and unpack it locally. And then import the directory. 

For using the existing STL algorithms effectively you have to familiarize yourself with available functionality. We have prepared a CUTE test project (`algorithm_trivia`) with a large set of test cases which require you to insert the correct STL algorithm in order to get the test green. It contains several test suites, each containing some test cases. Usually, those cases fail with the current implementation. We have replaced the original calls with dummy functions (`xxx`, `xxxx`, `xxxxx`, `xxxxxx`) that satisfy the interface. You don't have to worry about these helper functions. Your task is to fix the test cases by calling the correct STL algorithm (instead of the helper function).

Since there are quite a few algorithms you don't have to solve all algorithms at one. We suggest to solve 2-3 test suites each week. Each suite contains a hint header that lists the algorithms that have to be used in the corresponding suite file. Each algorithm is required once. Read the description of the algorithms first and then try to insert the correct calls. Some algorithms require a predicate. Most of the time we have used an `is_prime` function that just checks whether the parameter is prime.

Have Fun!



## c) Generating Anagrams

Write a program that reads a word from standard input and creates all possible anagrams (permutations of the letters in the word).

Use a data structure to collect the anagrams that keeps them in sorted order and eliminates duplicates.

On Linux/Mac/Unix you can read in the file /usr/share/dict/words into a data structure and filter your anagrams according to the valid words. Try this with short words first, otherwise generating the permutations might take a long time (factorial(size())).

How many anagrams forming a word according to your system's dictionary do you find for the word "listen" ?

**Extension:** Can you extend your program in a way that it also will check for valid anagrams consisting of multiple words, i.e., `"Vacation time" = "I am not active"` (might be a bit harder and slower). 
