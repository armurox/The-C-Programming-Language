# Chapter 1 - A Tutorial Introduction: Retrospective and Thoughts

## Section 1.1 - Getting started
It's always fun to go right back to the beginning of a language, and see how the creators describe a simple hello world program. Also, the book being so old, gives us some notable differences between the programs of today, and the simple `hello.c` program the authors give us in their first example. Their's is, quite simply:
```
#include <stdio.h>

main()
{
    printf("hello, world\n");
}
```

however, you will notice that my [hello.c](https://github.com/armurox/The-C-Programming-Language/blob/main/chapter_1/hello.c) file differs, with `main()` being replaced by `int main(void)`. Now, interestingly, both these versions compile, (using `cc hello.c`) and it will work perfectly. However, you will see the warning: `type specifier missing, defaults to 'int'; ISO C99 and later do not support implicit int [-Wimplicit-int] main()`, which is quite self-explanatory. I am, however, more partial to ` gcc -std=c99 -Wall -Wextra -pedantic hello.c -o hello` when compiling the program. This particular command would then tend to give you an extra warning when compiling based on the book example, of the type: `a function declaration without a prototype is deprecated in all versions of C [-Wstrict-prototypes]`. The command I use to compile the program provides me with extra warnings (and particularly the `-pedantic` flag gives us some extra style hints as well, such as throwing a warning if there is a missing newline at the end of the file). Regardless, despite these small changes, the original programm will still compile and run, which does show that C, despite all this time does not undergo too many significant changes, at least at this basic level so far.