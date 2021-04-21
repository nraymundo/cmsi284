**CMSI 284** Computer System Organization/Systems Programming, Spring 2019

# Assignment 0404
Our second C set is not strictly harder, but does use some slightly more sophisticated techniques such as memory allocation and multiple files.

## Background Reading
Pretty much all of the information you need can be found in Dr. Toal’s [Introduction to C](http://cs.lmu.edu/~ray/notes/c) page, as well as many other C programming sites on the web.

You will also want to reference the [reverse-range-in-place](https://github.com/dondi/bazaar/tree/master/reverse-range-in-place) sample to see how multiple files would be named and organized, including test programs. _(do note though that one of the files—indicated in the comments—is provided purely for information purposes and is actually an example of how **not** to include one file in another)_

## For Submission: From C to Shining C
Write the requested C programs. Note that for these programs, part of the exercise is to write them using a particular _structure_. Even though these programs can also be written in single monolithic files, precisely knowing how to _not_ write them that way is part of the point of the assignment.

### Madlib
Implement a `madlib` function in its own file, _madlib.c_, with this signature:

    char* madlib(char* template, char* adjective, char* noun, char* verb);

`template` should be a C format string with three `%s` placeholders, one each for the given `adjective`, `noun`, and `verb` strings. `madlib` should create a new string consisting of the `template` with its `%s` placeholders replaced by the three words (*cough* `sprintf` *cough*). For example,

    madlib("The %s %s likes to %s in the moonlight", "brilliant", "git", "swim")

…should evaluate to `The brilliant git likes to swim in the moonlight`.

Accompany your function file with a test harness, _madlib-test.c_, that uses the C `assert` function to show that your `madlib` function works properly.

### Madlib-by-Numbers
Implement an _ordered_ madlib function in its own file, _madlib-by-numbers.c_, with this signature:

    char* madlib_by_numbers(char* template, int word_count, char* words[]);

For this variation of the function, `template` should be a C format string where single digits `0` to `9` may be substituted by the corresponding word in the given `words` array. If a digit exceeds the maximum index in the `words` array (as indicated by the `word_count` parameter), no substitution takes place. As with `madlib`, a new string should be created. For example, given the string array `char* words_to_use[] = { "swim", "brilliant", "git" }`, the expression

    madlib_by_numbers("The 1 2 likes to 0 in the 1 moonlight", 3, words_to_use)

…should evaluate to `The brilliant git likes to swim in the brilliant moonlight`.

Note that `madlib_by_numbers` can do the following:
* Use a word multiple times: The same “word number” can appear in the template string more than once
* Substitute words in any order: Larger “word numbers” can appear before smaller ones

On the other hand, `madlib_by_numbers` can _not_ do the following:
* Substitute a double-digit index: e.g., `12` in the template string substitutes words `1` and `2`, not word `12`; if this appeared in the template string above, the substitution will be `brilliantgit`
* As such, it thus follows that `madlib_by_numbers` will not handle word lists of more than 10 elements: words `10` and above will simply have no place to go

To prevent potential vulnerabilities (can you see why?), `word_count` should not accept values greater than 10. A `word_count` of 10 or greater should return an empty string.

Accompany your file with a test harness, _madlib-by-numbers-test.c_, that uses the C `assert` function to show that your `madlib_by_numbers` function works properly.

_Protip:_ Strongly consider defining additional functions in _madlib-by-numbers.c_ that perform intermediate computations for you. This not only decreases the complexity of your individual functions, but provides additional units of functionality that you can test separately.

### Reverse Words

Use the sample `reverse_range_in_place` function to implement:

    void reverse_words(char* string);

This function does what you think it does: it reverses the words, in place, within the given string (i.e., a new string is not created; instead, the original string is modified into its reversed-words version). Note that modern languages generally don’t allow in-place string modification, opting to create new strings instead. With C, however, this remains possible.

To keep things simple, we will define a “word” as any sequence of non-space characters, including punctuation, numbers, etc. For example, if the string argument pointed to `Hello, my friends!`, `reverse_words` should change its contents into `friends! my Hello,`.

You may _not_ allocate additional memory, and the only other string function that you may use is `strlen`. Watch out for edge cases such as leading/trailing spaces, multiple spaces in between words, etc. _Big implementation clue:_ There is no need to particularly preserve multiple-space gaps. If those shift around in the resulting string, that’s OK.

Organize your source code as follows: place your function in _reverse-words.c_ with an accompanying header file _reverse-words.h_ (just like the included sample and starter code). Supply a test harness to demonstrate that your function works as specified; call this _reverse-words-test.c_. The original `reverse_range_in_place` code should not be modified, and used as provided.

## How to Turn it In
Commit the requested source code (and _just_ the source code)—header files, implementation files, and test files—to this repository. To avoid filename confusion, stubs for the requested files are already part of the repository. The `reverse_range_in_place` implementation has also been copied over from the GitHub bazaar.

## Specific Point Allocations
This assignment is scored according to outcomes _2a_, _2b_, and _4a_ to _4f_ in the [syllabus](https://dondi.lmu.build/spring2019/cmsi284/cmsi284-spring2019-syllabus.pdf). For this particular assignment, graded categories are as follows:

| Category | Points | Outcomes |
| -------- | -----: | -------- |
| **Madlib** | 30 points total | |
| • Compiles and runs without unexpected errors | 5 points | _4a_, _4d_ |
| • Correct functionality | 20 points | _2a_, _2b_, _4a_, _4d_ |
| • Adequate test cases | 5 points | _2a_, _2b_, _4a_, _4d_ |
| **Madlib-by-Numbers** | 35 points total | |
| • Compiles and runs without unexpected errors | 5 points | _4a_, _4d_ |
| • Correct functionality | 20 points | _2a_, _2b_, _4a_, _4d_ |
| • Adequate test cases | 10 points | _2a_, _2b_, _4a_, _4d_ |
| **Reverse Words** | 35 points total | |
| • Compiles and runs without unexpected errors | 5 points | _4a_, _4d_ |
| • Correct functionality | 20 points | _2a_, _2b_, _4a_, _4d_ |
| • Adequate test cases | 10 points | _2a_, _2b_, _4a_, _4d_ |
| Missing test program | deduction only | _4a_, _4b_ |
| Hard-to-maintain or error-prone code | deduction only | _4b_ |
| Non-compliant file structure | deduction only | _4b_ |
| Hard-to-read code | deduction only | _4c_ |
| Version control | deduction only | _4e_ |
| Punctuality | deduction only | _4f_ |
| **Total** | **100** |

Note that inability to compile and run to begin with will negatively affect correct functionality and the adequacy of test cases (because this will cast doubt on whether the tests work).
