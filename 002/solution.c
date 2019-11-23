#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
    if(argc != 2) {
        printf("USAGE: %s <highest number> \n", argv[0]);
        return EXIT_FAILURE;
    }
    unsigned int sum = 0;
    unsigned int max = atoi(argv[1]);

    unsigned int prev = 0;
    unsigned int cur = 1;
    unsigned int next;

    while(cur < max) {
        if(cur % 2 == 0)
            sum += cur;
        next = cur + prev;
        prev = cur;
        cur = next;
    }
    printf("%u\n", sum);
    return EXIT_SUCCESS;
}