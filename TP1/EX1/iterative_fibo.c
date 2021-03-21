#include "header.h"

int iterative_fibo(int n)
{
    int resultat = 0, nbr1 = 0, nbr2 = 1;
    if(n == 0) {return 0;}
    if(n == 1) {return 1;}
    for(int i = 0; i <= n; i++)
    {
        resultat = nbr1 + nbr2;
        nbr1 = nbr2;
        nbr2 = resultat;
    }
    return resultat;
}
