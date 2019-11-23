#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
    if(argc != 2) {
        printf("USAGE: %s <highest number> \n", argv[0]);
        return EXIT_FAILURE;
    }
    unsigned int sum = 0;
    int n = atoi(argv[1]);
    for(int i = 0; i < n; i++) {
        if( i % 3 == 0 || i % 5 == 0) {
            sum += i;
        }
    }
    printf("%u\n", sum);
    return EXIT_SUCCESS;
}