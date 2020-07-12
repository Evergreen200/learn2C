#include <stdio.h>
#include <stdlib.h>

int main(void) {
   
    int ai(void);
    for (int i = 0; i < 9; i++) {
        printf("%d\n", ai());
    }

    return 0;
}

int ai(void) {
   int x = rand() % 9 + 1;
   return x;
}
