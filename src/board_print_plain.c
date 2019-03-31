#include "board_print_plain.h"
#include <stdio.h>
#include <string.h>

extern char desk[8][8];
extern char input[5];
extern int x1, x2, y1, y2;

int chartoint(char input[5]);

void printdesk()
{
    int i, j;
    for (i = 0; i < 8; i++) {
        printf("%d ", 8 - i);
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

void scanan()
{
    char input[6];
    printf("Введите координаты: ");
    fgets(input, 6, stdin);
    if (chartoint(input)) {
        printf("Правильно\n");
    } else {
        printf("Не правильно\n");
    }
}

int chartoint(char input[5])
{
    x1 = (int)input[0] - 'A';
    y1 = (int)input[1] - '1';
    x2 = (int)input[3] - 'A';
    y2 = (int)input[4] - '1';
    if ((x2 < 8) && (x2 >= 0) && (y2 >= 0) && (y2 < 8)
        && (x1 >= 0) && (x1 < 8) && (y1 >= 0) && (y1 < 8))
        return 1;
    return 0;
}