#include <stdio.h> // includes standard input output
#include <stdlib.h> // includes stadard library
//#include "conio.h"
#define LINUX 1 // /defines LINUX as platform
//#define WINDOWS 1

void console_clean_screen(void) {
    #ifdef LINUX
    system("clear"); // cleares the screen
    #endif
    #ifdef WINDOWS
    system("cls");
    #endif
}

char square[10] = {'o', '1', '2', '3', '4', '5', '6', '7', '8', '9'}; // board

int checkwin(void);
void board(void);
int choice_of_player(void);

int main(void) {
    int player, i, choice;
    char mark;

    do {
        int e = choice_of_player(); 
        if (e == 1) {
           

        } else {

        board(); // first, printing board
        player = (player % 2 != 0) ? 1 : 2; // if player % 2 != 0 it's player 1's turn, else player 2's
        printf("Player %d, enter a number: ", player);
        int check = scanf("%d", &choice); // checks if the input is ok 
        
        if(check != 1) {
            printf("Error: Input");
            return 1;
        }

        mark = (player == 1) ? 'X' : 'O'; // the sign is set to the player, which turn is

        if (choice == 1 && square[1] == '1') {// if the field is free, the player can set in this, else there is a warning
            square[1] = mark;
        } else if (choice == 2 && square[2] == '2') {
            square[2] = mark;
        } else if (choice == 3 && square[3] == '3') {
            square[3] = mark;
        } else if (choice == 4 && square[4] == '4') {
            square[4] = mark;
        } else if (choice == 5 && square[5] == '5') {
            square[5] = mark;
        } else if (choice == 6 && square[6] == '6') {
            square[6] = mark;
        } else if (choice == 7 && square[7] == '7') {
            square[7] = mark;
        } else if (choice == 8 && square[8] == '8') {
            square[8] = mark;
        } else if (choice == 9 && square[9] == '9') {
            square[9] = mark;
        } else {
            printf("Invalid move "); // warning

            player--; 
            //getch();
            getchar();
        }
        i = checkwin();
        player++;
        }    
    } while (i == - 1); // while i -1: while nobody has enough signs in a row (...)

    board(); // prints the board out 

    if (i == 1) {
        printf("==> Player %d win \n", --player);
    } else {
        printf("==> Game draw\n");
    }
    //getch();
    getchar();
    
    
    return 0;

}


int checkwin(void) { 
    if (square[1] == square[2] && square[2] == square[3]){ // checks if the field (in a row or a column etc.) have the same sign+
        return 1;
    } else if (square[4] == square[5] && square[5] == square[6]) {
        return 1;
    } else if (square[7] == square[8] && square[8] == square[9]) {
        return 1;
    } else if (square[1] == square[4] && square[4] == square[7]) {
        return 1;
    } else if (square[2] == square[5] && square[5] == square[8]) {
        return 1;
    } else if (square[3] == square[6] && square[6] == square[9]) {
        return 1;
    } else if (square[1] == square[5] && square[5] == square[9]) {
        return 1;
    } else if (square[3] == square[5] && square[5] == square[7]) {
        return 1;
    } else if (square[1] != '1' && square[2] != '2' && square[3] != '3' && square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7] != '7' && square[8] != '8' && square[9] != '9') {
        return 0; 
    } else {
        return - 1; // if this will be executed, the while loop will go on 
    }


}

void board(void) {

    console_clean_screen();
    printf("\n\nTic Tac Toe\n\n");
    printf("Player 1 (X) - Player 2 (O)\n");
    
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", square[1], square[2], square[3]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", square[4], square[5], square[6]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", square[7], square[8], square[9]);

    printf("     |     |     \n\n");   
}

int choice_of_player(void) {
    printf("Do you want to play against a friend[0] or the ai[1]: ");
    int a = getchar();
    switch (a) {
        case 0: printf("You'll play against a friend.\n");
                break;
        case 1: printf("You'll play against a ai.\n");
                break;
        default: printf("Something got wrong!");
    }
    return a;
}

int ai(void) {
    int x = rand() % 9 + 1;   
    return x;
}
