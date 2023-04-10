#include <stdio.h>

int main() {
    int i = 11;
    
    // while loop
    printf("while loop:\n");
    {
        while (i < 10) {
            printf("%d\n", i);
            i++;
        }
    }
    
    i = 11;  
    
    // for loop
    printf("for loop:\n");
    {
        for (; i < 10;) {
            printf("%d\n", i);
            i++;
        }
    }
    
    i = 11;\
    
    // do-while loop
    printf("do-while loop:\n");
    {
        do {
            printf("%d\n", i);
            i++;
        } while (i < 10);
    }
    
    return 0;
}


/* The while and for loops are checked before the body is executed. 
On the other hand, the do-while loop is executed before checking the loop condition. 
The first and second statement does not execute the loop body at all if the statement is false, 
but the last statement executes the body at least once. 

Thus, the last statement is not equivalent to the first two assuming the loop bodies are the same. */