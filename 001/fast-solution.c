#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
    if(argc != 2) {
        printf("USAGE: %s <highest number> \n", argv[0]);
        return EXIT_FAILURE;
    }

    unsigned long n = atoi(argv[1]) - 1;     // < input, not <= input
    unsigned long mult_3 = n / 3;
    unsigned long mult_5 = n / 5;
    unsigned long mult_15 = n / 15;

    unsigned long sum = (mult_3 * (mult_3 + 1)) / 2 * 3;
    sum += (mult_5 * (mult_5 + 1)) / 2 * 5;
    sum -= (mult_15 * (mult_15 + 1)) / 2 * 15;

    printf("%lu\n", sum);
    return EXIT_SUCCESS;
}