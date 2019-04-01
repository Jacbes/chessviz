#include "board.h"
#include <stdio.h>
#include <string.h>

extern char desk[8][8];
char input[7];
int X1, X2, Y1, Y2;

void scanan()
{
    printf("Введите координаты: ");
    fgets(input, 7, stdin);
    if (chartoint(input)) {
        printf("Правильно ввел\n");
        if (white()) {
            move();
        } else {
            printf("Не правильно походил\n");
        }
    } else {
        printf("Не правильно\n");
    }
}

int chartoint(char input[7])
{
    X1 = (int)input[0] - 'A';
    Y1 = (int)input[1] - '1';
    X2 = (int)input[3] - 'A';
    Y2 = (int)input[4] - '1';
    if ((X2 < 8) && (X2 >= 0) && (Y2 >= 0) && (Y2 < 8) && (X1 >= 0) && (X1 < 8)
        && (Y1 >= 0) && (Y1 < 8))
        return 1;
    return 0;
}

int white()
{
    if (desk[Y1][X1] > 64 && desk[Y1][X1] < 73) {
        return 0;
    }
    switch (desk[Y1][X1]) {
    case 'P':
        if ((desk[Y2][X2] == ' ') && (Y1 == 1) && (X1 == X2) && (Y2 - Y1 > 0)
            && (Y2 - Y1 < 3)) {
            return 1;
        }
    }
    return 0;
}

void move()
{
    desk[Y2][X2] = desk[Y1][X1];
    desk[Y1][X1] = ' ';
}