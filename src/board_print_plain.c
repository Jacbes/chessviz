#include <stdio.h>
#include "board_print_plain.h"

extern char numbers[8];
extern char desk[8][8];

void printdesk()
{
    int i, j;
    for (i = 0; i < 8; i++) {
        printf("%d ", numbers[i]);
        for (j = 0; j < 8; j++) {
            printf("%c ", desk[i][j]);
        }
        printf("\n");
    }
    printf("  ");
    for (i = 0; i < 8; i++)
        printf("%c ", i + 97);
    printf("\n");
}