**CMSI 284** Computer System Organization/Systems Programming, Spring 2019

# Assignment 0507
For our culminating set of programs, we try to bridge all of the material from the semester by writing programs consisting of both C and assembly language source code, invoking each in both directions.

## Background Reading
Dr. Toal’s assembly language pages (all linked from the [course website](https://dondi.lmu.build/spring2019/cmsi284)), and particularly the later sections of his [NASM Tutorial](https://cs.lmu.edu/~ray/notes/nasmtutorial/), comprise the main sources of information for this assignment. In particular, get to know the _maxofthree_, _sum_, and _factorial_ sample programs.

## For Submission: Welcome to the _.o_, C
If the reference isn’t apparent to you, don’t worry about it. The main point of this assignment is for you to demonstrate that you can call C functions from assembly language (you have already done this with _library_ functions but now you’ll do it with a function whose source code you supply) and, more importantly, call assembly language functions from C.

### `main` in Assembly, Function in C
Write an assembly language program, _reverse-echo.asm_, that uses _reverse-range-in-place.c_ to echo its command-line arguments, including the program name, but in reverse.

Notice how, because assembly language is the _caller_ of `reverse-range-in-place`, no _.h_ file is necessary. This should give you some additional insight on the role that _.h_ files play in C (if it hasn’t clicked for you already).

Sample program invocation and output:

    $ ./reverse-echo
    ohce-esrever/.

    $ ./reverse-echo Is this a superpower?
    ohce-esrever/.
    sI
    siht
    a
    ?rewoprepus

Note that this program won’t really have any erroneous arguments, so no error messages are expected.

As with previous assignments, the grading of this assignment will be semi-automated, so it is very important that you adhere strictly to the specified format for the reversed arguments (i.e., one line per argument).

### `main` in C, Function in Assembly
Implement Euclid’s algorithm for calculating the greatest common divisor (GCD) of two numbers as a function _in assembly language_ and write a C program, _callgcd.c_, that calls that function on user-supplied command-line arguments. Place the GCD implementation in _gcd.asm_.

In pseudocode, Euclid’s GCD algorithm is:

    gcd(x, y) = (y == 0) ? x : gcd(y, x % y)

Sample program invocation and output:

    $ ./callgcd 24 16
    The GCD of 24 and 16 is 8.

    $ ./callgcd 14 90
    The GCD of 14 and 90 is 2.

If the wrong number of command line arguments is supplied, the program should respond as follows:

    $ ./callgcd
    This program requires exactly two non-negative integer command line arguments.

Or:

    $ ./callgcd 78 12 33
    This program requires exactly two non-negative integer command line arguments.

Because `atoi` just returns `0` on bad input values, don’t worry about detecting those:

    $ ./callgcd bazinga bigchungus
    The GCD of 0 and 0 is 0.

However, this time you _do_ have to check for negative numbers, because those values will not terminate:

    $ ./callgcd 8 -4
    This program requires exactly two non-negative integer command line arguments.

As with previous assignments, the grading of this assignment will be semi-automated, so it is very important that you adhere strictly to the specified output messages and format.

## How to Turn it In
Commit your source code (and _just_ the source code)—i.e., _reverse-echo.asm_, _gcd.asm_, and _callgcd.c_ (_reverse-range-in-place.c_ is already supplied)—to this repository.

## Specific Point Allocations
This assignment is scored according to outcomes _2a_, _2b_, _2c_, _2d_, _3a_, _3b_, and _4a_ to _4f_ in the [syllabus](https://dondi.lmu.build/spring2019/cmsi284/cmsi284-spring2019-syllabus.pdf). For this particular assignment, graded categories are as follows:

| Category | Points | Outcomes |
| -------- | -----: | -------- |
| _reverse-echo_ | 35 points total | |
| • Assembles, links, and runs without unexpected errors | 10 | _3a_, _4a_, _4d_ |
| • Correct program output or result | 25 | _2c_, _2d_, _3b_, _3c_, _4a_, _4d_ |
| _gcd_ | 65 points total | |
| • Compiles, assembles, links, and runs without unexpected errors | 15 | _3a_, _4a_, _4d_ |
| • Correct program output or result | 35 | _2c_, _2d_, _3b_, _3c_, _4a_, _4d_ |
| • Correct handling of invalid user input | 15 | _2c_, _2d_, _3b_, _3c_, _4a_, _4d_ |
| Hard-to-maintain or error-prone code | deduction only | _4b_ |
| Hard-to-read code | deduction only | _4c_ |
| Version control | deduction only | _4e_ |
| Punctuality | deduction only | _4f_ |
| **Total** | **100** |

_reverse-echo_ is worth fewer points because there is no need for argument checking and the C portion is already written for you—you just need to iterate through `argv` and call the function correctly. Thus, overall, it should take less work. _gcd_ includes a recursive calculation in assembly language and checks the arguments more deeply. (although these checks are in C…you realized that right?)

Note that inability to assemble, link, and run to begin with will negatively affect the correctness of program output and proper handling of invalid user input.
