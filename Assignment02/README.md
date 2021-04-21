**CMSI 284** Computer System Organization/Systems Programming, Spring 2019

# Assignment 0425
For these assembly language programs, we go back to how we started, with _system calls_—those built-in operating system-level services invoked by `syscall`.

## Background Reading
In addition to Dr. Toal’s assembly language pages (all linked from the [course website](https://dondi.lmu.build/spring2019/cmsi284)), you’ll want to scan this [list of 64-bit Linux system calls](https://filippo.io/linux-syscall-table/) (or [this one](http://blog.rchapman.org/posts/Linux_System_Call_Table_for_x86_64/)) in order to pick the one which you’ll invoke for this assignment. When you see a system call that you find interesting, just do a web search for something like “Linux 64-bit system call `system_call_name`” to find more detailed information about that system call.

You have seen examples for `write` and `exit`—there’s lots more you can do!

## For Submission: System Call Me Maybe

Examine the aforementioned lists of 64-bit Linux system calls and pick a system call that you find interesting. Implement an assembly language program that invokes that system call using any applicable command-line arguments and displays appropriate message or output. This is pretty much how Linux operating system commands are implemented!

Some implementation notes/tips:
* Nearly all system calls require some set of parameters so you will want to link with `gcc` in order to have easy access to `argc` and `argv` as usual, as well as library functions like `atoi`, `puts`, and `printf`. Be cognizant of the system call parameters’ data types (`int`, `char*`, etc.).
* Keep things simple. Some system calls return complex structures—great information and definitely interesting, but likely over your head.
* Choose something whose result is easily demonstrable, such as easily verifiable information or concrete, tangible results (like those mentioned in the next item).
* System calls that manipulate files (such as `rename`, `mkdir`, `chmod`, or `unlink`) don’t necessarily have direct output but instead affect the specified file or folder. These can be “no news is good news” programs, but do display a message if an error is detected. You can examine the affected file(s) or folder(s) to see if your system call worked.
* Remember that you are supposed to invoke the system call _directly_, not through C. If your code doesn’t have the `syscall` instruction, then you’re doing it wrong.
* One system call is off-the-table: `chdir`. Calling this in a separate program won’t work as you expect. You’ll see why when you learn about process management in Operating Systems. `write` and `exit` are also off the table for (I hope) obvious reasons. However, you may use these system calls in supporting roles.
* Yes there is a `reboot` system call. It does what it says, so save your work if you want to try invoking it.
* If you decide to use a system call that delivers its results to a block of memory that you supply, it will be easier to just use `resb` in the `.data` section to pre-allocate space rather than to dynamically allocate memory via `malloc`.

## How to Turn it In
Commit your source code (and _just_ the source code)—i.e., the _.asm_ file—to this repository. Filenames will vary because they will depend on the system call that you choose.

## Specific Point Allocations
This assignment is scored according to outcomes _2c_, _2d_, _3a_, _3b_, _3c_, and _4a_ to _4f_ in the [syllabus](https://dondi.lmu.build/spring2019/cmsi284/cmsi284-spring2019-syllabus.pdf). For this particular assignment, graded categories are as follows:

| Category | Points | Outcomes |
| -------- | -----: | -------- |
| • Assembles, links, and runs without unexpected errors | 20 points | _3a_, _4a_, _4d_ |
| • Correct system call invocation (`syscall`) | 10 points | _3c_, _4a_, _4d_ |
| • Correct program output or result | 40 points | _2c_, _2d_, _3b_, _3c_, _4a_, _4d_ |
| • Correct handling of invalid user input or erroneous results | 30 points | _2c_, _2d_, _3b_, _3c_, _4a_, _4d_ |
| Hard-to-maintain or error-prone code | deduction only | _4b_ |
| Hard-to-read code | deduction only | _4c_ |
| Version control | deduction only | _4e_ |
| Punctuality | deduction only | _4f_ |
| **Total** | **100** |

Note that inability to assemble, link, and run to begin with will negatively affect the correctness of program output and proper handling of invalid user input.
