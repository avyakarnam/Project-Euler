#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
    if(argc != 2) {
        printf("USAGE: %s <highest number> \n", argv[0]);
        return EXIT_FAILURE;
    }
    unsigned long sum = 0;
    unsigned long n = atoi(argv[1]);
    for(unsigned long i = 0; i < n; i++) {
        if( i % 3 == 0 || i % 5 == 0) {
            sum += i;
        }
    }
    printf("%lu\n", sum);
    return EXIT_SUCCESS;
}