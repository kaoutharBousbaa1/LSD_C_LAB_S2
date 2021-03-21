#include "header.h"

// ? Note: A static function in C is a function that has a scope that is
// limited to its object file. This means that the static function is only
// visible in its object file.
// A function can be declared as static function by placing the static keyword
// before the function name

static bool    is_prime(int n)
{
    for(int i = 2; i<abs(n)-1; i++)
    {
        if(n%i == 0)
            return 0;
    }
    return 1;
}

void get_primes(int n)
{
    for(int i = 2; i<=n; i++)
    {
        if(is_prime_opt(i))
            print(" %d is prime\n", i);
    }
} 

