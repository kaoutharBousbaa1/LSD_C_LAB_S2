/*
** Another stange file with the extension .h not .c
** these type of files called header files.
** The primary purpose of a header file is to propagate declarations to code
** files. Header files allow us to put declarations in one location and then
** import them wherever we need them. This can save a lot of typing in
** multi-file programs.
** for more info: https://www.geeksforgeeks.org/header-files-in-c-cpp-and-its-uses/
*/

#ifndef HEADER
#define HEADER

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>

void    get_primes(int n);
void    get_primes_opt(int n);

#endif
