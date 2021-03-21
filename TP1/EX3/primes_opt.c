#include "header.h"

// ? Note: A static function in C is a function that has a scope that is
// limited to its object file. This means that the static function is only
// visible in its object file.
// A function can be declared as static function by placing the static keyword
// before the function name

static bool    is_prime_opt(int n)
{
    if(n == 2)
        return 1;
    if(n < 2 || n%2==0)
        return 0;
    for(int i = 3; i<= sqrt(n); i=i+2)
    {
        if(n%i == 0)
            return 0;
    }
    return 1;
}

void get_primes_opt(int n)
{
    if(n>2)
        print(2);
    for(int i = 3; i<=n; i+=2)
    {
        if(is_prime_opt(i))
            print("%d is prime\n", i);

    }
}
