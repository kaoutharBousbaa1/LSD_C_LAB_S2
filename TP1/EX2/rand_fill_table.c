#include "header.h"

/*
** Hint: You need to use rand function for generating random numbers
** and to get out of getting the same series of random numbers every time
** you run the program you need to use srand.
** https://www.geeksforgeeks.org/rand-and-srand-in-ccpp/
*/
void rand_fill_table(int *tab, int size)
{
    int maximal = 0; i = 0; p = 0; q = 0; k = 0; j = 0;
    const int MAX = 20; MIN = 0;
    srand(time(NULL));
    for(int i = 0; i<size; i++)
    {
        tab[i] = (rand() % (MAX - MIN +1)) + MIN;
    }
}
