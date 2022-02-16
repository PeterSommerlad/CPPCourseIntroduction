# 2. Optional exercises (also for self-study)

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
