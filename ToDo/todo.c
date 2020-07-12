/* Developed on and for linux; this program probably does not work on other platforms.
 * Evergreen200
 */ 
#include <stdio.h>
#include <stdlib.h>
#define LINUX 1

void clean_screen(void) {
    #ifdef LINUX 
    system("clear"); 
    #endif
}

int main(void) {
    int list_entry(void); 
    void list(void);
    int i;

    do {
        list();
        list_entry();
        i = list_entry();
    } while(i == 1);


    return EXIT_SUCCESS;
}

int list_entry(void) {
    int x;
    printf("Do you have anything (else) to do? No, Yes [0-1]: ");
    int check = scanf("%d\n", &x);
    if (check != 1 && (x > 1 || x < 0)) {
        printf("Error: Input!");
        return EXIT_FAILURE;
    } else {
        return x;
    }
    return EXIT_FAILURE;
}

void list(void) {
    clean_screen();
    printf("\nTermList - Cool ToDo list in your terminal\n\n");
     
}
