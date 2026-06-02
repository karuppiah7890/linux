Interesting nuances that I read about

- The advantage of using `#define _GNU_SOURCE` on top of the `.c` source file. Apparently - the primary advantage of using `#define _GNU_SOURCE` is gaining access to advanced, optimized, and highly convenient features that are missing from standard C and POSIX libraries.

- `pthread_create()` returns error - that's the standard and does NOT set `errno` like standard library calls like `open`, `malloc`, `write`. But there are some implementations where `pthread_create()` sets the `errno` too, but it's not always the case. So, it's often better to use the return value of `pthread_create()` to detect any errors in `pthread_create()` to write portable code in C

- `perror()` uses the `errno` to print the error details

- Linux Manual Page has sections. It has numbered sections, usually 8 sections - from section 1 to section 8. So, if you see `pthread_create(3)`, the `(3)` means `pthread_create` is in section 3. Some keywords are present in multiple sections and hence the numbering and if you just type `man <keyword>`, it will show the manual that comes first - the very first entry, searching from section 1 usually. You can use `man <section-number> <keyword>` to get that particular section. To find all sections for a given keyword, use `man -f <keyword>`

- `errno` command line utility to find out what's the meaning of a given status code / return code / error number. For example, `11` is `EAGAIN`

```bash
sudo apt install moreutils

man errno

errno 11

errno EAGAIN

errno --search <keyword>

errno --list
```
