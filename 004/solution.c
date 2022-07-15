/*
 * Some very basic math
 *
 * The solution is probably 6 digits, so can be wriiten as
 *     abccba
 * or equivalently
 *     a*100000 + b*10000 + c*1000 + c*100 + b*10 + a
 *   = a*100001 + b*10010 + c*1100
 *   = a*11*9091 + b*11*910 + c*11*100
 *   = 11*(a*9091 + b*910 + c*100)
 * so the solution must be divisible by 11 => one of the factors must be
 * a multiple of 11
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Checks if a 6 digit number is a palindrome */
int is_palindrome(int n) {
   /* 
    * naively, we could check each digit pair, like the following
    * n / 100000 == n % 10 &&
    * n / 10000 % 10 == n / 10 % 10 &&
    * n / 1000 % 10 == n / 100 % 10
    *
    * which requires 10 div/mod operations (could probably be optimized to
    * less by the compiler by using both results of a div asm instruction)
    *
    * instead, split n into its upper and lower halves
    *     upper = n / 1000   (note the integer division)
    *     lower = n % 1000
    * then try to reverse one of the halves. if the forward and reverse
    * are equal, then the number is a palindrome
    *     upper == rev(lower) => n is a palindrome
    *
    * consider the 3 digit lower:
    *     lower = abc = a*100 + b*10 + c
    * to reverse it, we want to calculate 
    *     rev(lower) = cba = c*100 + b*10 + a
    * which could be done as
    *     rev(lower) = (lower % 10)*100 + (lower / 10 % 10)*10 + (lower / 100)
    * using 8 arithmetic operations
    *
    * however, notice that the middle digit stays the same, so recomputing it
    * seems unnecessary. consider instead the difference
    *     rev(lower) - lower = (c*100 + b*10 + a) - (a*100 + b*10 + c)
    *                        = c*99 - a*99
    *                        = (c - a)*99
    * so
    *     rev(lower) = lower + (c - a)*99
    *                = lower + ( (lower % 10) - (lower / 100) )*99
    * which takes 5 arithmetic operations
    *
    * in combination with the initial split, this entire function uses 7
    * arithmetic operations (and 1 check for integer equality)
    */
    
    int upper = n / 1000;
    int lower = n % 1000;

    int lower_rev = lower + ((lower % 10) - (lower / 100))*99;

    return upper == lower_rev;
}

int main(int argc, char const *argv[]) {
    int sol = 0;
    int sol_i, sol_j;

    for(int i = 999; i > 99; i -= 11) {
        for(int j = 999; j > 99; j--) {
	    int prod = i*j;
            if(prod > sol && is_palindrome(prod)) {
                sol = prod;
                sol_i = i;
                sol_j = j;
                break;
	    } else if(prod < sol) {
                break;
            }
        }
    }

    printf("%d * %d = %d\n",sol_i, sol_j, sol);    

    return 0;
}
