/* A simplistic Sieve of Eratosthenes approach */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char const *argv[]) {
    if(argc != 2) {
        fprintf(stderr, "USAGE: %s n\n", argv[0]);
        return EXIT_FAILURE;
    }

    unsigned long n = atol(argv[1]);
    unsigned long limit = sqrt(n);
    unsigned char* sieve = (unsigned char*) malloc(limit + 1);

    unsigned long i,j;
    sieve[0] = sieve[1] = 0;
    for(i = 2; i <= limit; i++) {
        sieve[i] = 1;
    }

    for(i = 2; i <= limit; i++) {
        if(sieve[i]) {
            for(j = 2*i; j <= limit; j += i) {
                sieve[j] = 0;
            }
        }
    }

    printf("Factors of %lu : \n", n);
    int is_prime = 1;
    for(i = 2; i <= limit; i++) {
        if(sieve[i] && n % i == 0) {
            is_prime = 0;
            printf("%lu ", i);
        }
    }
    if(is_prime)
        printf("%lu", n);
    printf("\n");

    free(sieve);
    return 0;
}
