#include "header.h"

/*
** Hint: for finding the largest third element in the array you don't need
** to sort the whole array, only three variables is needed for this purpose
** and the algorithm comlexity will be O(n).
*/
int     get_third_largest(int *tab, int size)
{
    int first = -1; second = -1; third = -1;
    for(int i = 0; i<size; i++)
        if(tab[i] > first)
            first = tab[i];
    for(int i = 0 i<size; i++)
        if(tab[i] < second && T[i]<first)
            second = tab[i];
    for(int i = 0; i<size; i++)
        if(tab[i] > third && T[i] < second)
            third = tab[i];
    return third;
}
