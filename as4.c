#include <stdio.h>

int main() {
    int n;
    
    // prints the table header
    printf("TABLE OF POWERS OF TWO\n");
    printf("n\t2 to the n\n");
    printf("--\t--------\n");
    
    // loops through the values of n from 0 to 9
    for (n = 0; n <= 9; n++) {
        // prints the value of n and 2^n
        printf("%d\t%d\n", n, 1 << n);
    }
    
    return 0;
}
