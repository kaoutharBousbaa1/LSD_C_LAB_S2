/*
** Another stange file with the extension .h not .c
** this file called header files, b
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
#include <time.h>// for rand and srand functions

void    print_table(int *tab, int size);
void    rand_fill_table(int *tab, int size);
int     get_third_largest(int *tab, int size);

#endif
