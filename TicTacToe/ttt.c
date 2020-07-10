#include <stdio.h>
#include "conio.h"
#define LINUX 1
//#define WINDOWS 1

void console_clean_screen(void) {
    #ifdef LINUX
    system("clear");
    #endif
    #ifdef WINDOWS
    system("cls");
    #endif
}

char square[10] = {'o', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

int checkwin(void);
void board(void);

int main(void) {
    int player, i, choice;
    char mark;

    do {
        board();
        player = (player % 2 != 0) ? 1 : 2;
        printf("Player %d, enter a number: ", player);
        int check = scanf("%d", &choice);
        
        if(check != !) {
            printf("Error: Input");
            return 1;
        }

        mark = (player == 1) ? 'X' : 'O';
    }

}


int checkwin(void) {
    
}

int board(void) {
    console_clean_screen();
    printf("\n\nTic Tac Toe\n\n");
    printf("Player 1 (X) - Player 2 (O)");
    
    printf("     |     |     \n");
    printf(" %c   |  %c  |  %c  \n", square[1], square[2], square[3]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", square[4], square[5], square[6]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", square[7], square[8], square[9]);

    printf("     |     |     \n\n");   
}

