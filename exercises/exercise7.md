# Exercise 7:  Applications of `std::map` and `std::set`

In this exercise you will facilitate an associative container to create a histogram of `Word` (your own `Word` class) objects and use an `std::set` to create a sorted occurrence structure.

## Histogram Function

Create the header and source files `statistics.h` and `statistics.cpp` featuring a namespace `statistics`. In these files implement a function `histogram` that counts `Word` occurrences on an `std::istream` and creates an `std::map` with the `Word` as key and the count of type `int` as value:

```cpp
namespace statistics {

std::map<Word, int> histogram(std::istream &);

}
```

Example input:

```
Wenn hinter Fliegen Fliegen fliegen, fliegen Fliegen Fliegen nach.
```

Expected content of the `std::map`:

```
Fliegen: 6
hinter: 1
nach: 1
Wenn: 1
```


## `HistogramEntry` Class

As preparation for the next step implement a helper class `HistogramEntry`, which will be used as element type for `std::set` later. It is a class that contains the `Word` and its number of occurrences. In order to use this type in an `std::set` and to print them you should implement the following operators:

* Comparison operations: `<`, `>`, `<=`, `>=`, `==` and `!=`
* The semantics of the `<` operator should be that a `HistogramEntry` is less than if the occurrence count is larger, or if the count is equal the `<` comparison of `Word` is used.

```cpp
HistogramEntry books{Word{"Book"}, 2};
HistogramEntry cups{Word{"Cup"}, 2};
HistogramEntry pens{Word{"Pen"}, 1};

// books < cups
// books < pens
// cups < pens
```

* Output operator for `std::ostream`: `<<`

```cpp
HistogramEntry sheets{Word{"Sheet"}, 5};
std::cout << sheets; //prints: Sheet: 5
```


## Find Top N Elements

Implement a function `top` in the `statistics` namespace that prints the `n` most frequent `Word`s given a histogram-`map` from above. Signature for `top`:

```cpp
namespace statistics {
std::set<HistogramEntry> top(std::map<Word, int> const & occurrences, int n);
}
```

**Note:**
* If number of elements in `occurrences` is less than `n` all elements are contained in the result.
* To get from `std::map` entries to `HistogramEntry`s you can use `std::for_each` or sneak-peek at `std::transform` and `std::inserter`. We will cover them next week.


## Print Top N Elements

Implement a function `printOccurrences` that takes an `std::istream`, an `std::ostream` and an `int n`. It reads the words from the `std::istream` and prints the `n` most frequent words and their number of occurrence on the `std::ostream`.

```cpp
void printOccurrences(std::istream &, std::ostream &, int n);
```
