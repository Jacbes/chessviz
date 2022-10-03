#include "board.h"
#include "board_print_plain.h"
#include <stdio.h>

int X1, X2, Y1, Y2;
char desk[8][8] = {{'R', 'N', 'B', 'K', 'Q', 'B', 'N', 'R'},
                   {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
                   {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                   {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                   {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                   {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                   {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
                   {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}};

int main() {
    int playerWin;

    printf("     Шахматы\n");
    printf("Пример обычного хода: E2-E4\n");
    printf("Пример хода взятия: E2xE4\n");

    printDesk();

    while (1) {
        printf("Белые (Большие буквы):");
        inputStringOfMove(1);
        updateDesk();
        printDesk();
        playerWin = checkWin(1);
        if (playerWin) {
            break;
        }

        printf("Черные (Маленькие буквы):");
        inputStringOfMove(2);
        updateDesk();
        printDesk();
        playerWin = checkWin(2);
        if (playerWin) {
            break;
        }
    }

    printf("Player %d win\n", playerWin);

    return 0;
}
