#include "board.h"
#include <stdio.h>

extern int X1, X2, Y1, Y2;
extern char desk[8][8];

void inputStringOfMove(int colorOfPlayer) {
    while (1) {
        char stringOfMove[7];
        while (1) {
            fgets(stringOfMove, 7, stdin);
            if (parseStringOfMoveToCoordinates(stringOfMove)) {
                break;
            }
            printf("Введите заново:");
        }
        if (colorOfPlayer == 1) { // белые
            if (moveWhiteFigure(stringOfMove) == 1) {
                break;
            } else {
                printf("Введите заново:");
            }
        }
        if (colorOfPlayer == 2) { // черные
            if (moveBlackFigure(stringOfMove) == 1) {
                break;
            } else {
                printf("Введите заново:");
            }
        }
    }
}

int parseStringOfMoveToCoordinates(const char stringOfMove[]) {
    if ((stringOfMove[2] != '-') && (stringOfMove[2] != 'x')) {
        return 0;
    }

    X1 = (int) stringOfMove[0] - 'A';
    Y1 = (int) stringOfMove[1] - '1';
    X2 = (int) stringOfMove[3] - 'A';
    Y2 = (int) stringOfMove[4] - '1';

    if ((stringOfMove[2] == 'x') && (desk[Y2][X2] == ' ')) {
        printf("Вроде никого нет, чтобы рубить?\n");
        return 0;
    }
    if ((X2 < 8) && (X2 >= 0) && (X1 >= 0) && (X1 < 8)
        && (Y2 >= 0) && (Y2 < 8) && (Y1 >= 0) && (Y1 < 8)) {
        return 1;
    }

    return 0;
}

int moveWhiteFigure(const char stringOfMove[]) {
    if ((desk[Y2][X2] > 'A') && (desk[Y2][X2] < 'S')) {
        return 0; //не рубим своих
    }

    switch (desk[Y1][X1]) {
        case 'P':
            if ((stringOfMove[2] == '-') && (desk[Y2][X2] != ' ')) {
                printf("Вроде надо рубить?\n");
                break;
            }
            if ((desk[Y2][X2] == ' ') && (Y1 == 1) && (X1 == X2) && (Y2 - Y1 > 0)
                && (Y2 - Y1 < 3) && checkYCoordinateMove()) {
                return 1; //начальный ход
            }
            if ((desk[Y2][X2] == ' ') && (X2 == X1) && (Y2 - Y1 == 1)) {
                transformPawnToNewFigure();
                return 1; //ход по пустым клеткам
            }
            if ((desk[Y2][X2] < 's' && desk[Y2][X2] > 'a')
                && ((X2 - X1 == 1) || (X2 - X1 == -1)) && (Y2 - Y1 == 1)
                && (stringOfMove[2] == 'x')) {
                return 1; //рубим чужих
            }
            break;
        case 'R':
            if ((stringOfMove[2] == '-') && (desk[Y2][X2] != ' ')) {
                printf("Вроде надо рубить?\n");
                break;
            }
            if ((Y2 == Y1) && (checkXCoordinateMove())) {
                return 1;
            }
            if ((X2 == X1) && (checkYCoordinateMove())) {
                return 1;
            }
            break;
        case 'N':
            if ((stringOfMove[2] == '-') && (desk[Y2][X2] != ' ')) {
                printf("Вроде надо рубить?\n");
                break;
            }
            if ((Y1 - Y2 == 2) && (X1 - X2 == 1)) {
                return 1;
            }
            if ((Y2 - Y1 == 2) && (X2 - X1 == 1)) {
                return 1;
            }
            if ((Y2 - Y1 == 2) && (X1 - X2 == 1)) {
                return 1;
            }
            if ((Y1 - Y2 == 2) && (X2 - X1 == 1)) {
                return 1;
            }
            if ((Y1 - Y2 == 1) && (X2 - X1 == 2)) {
                return 1;
            }
            if ((Y2 - Y1 == 1) && (X2 - X1 == 2)) {
                return 1;
            }
            if ((Y1 - Y2 == 1) && (X1 - X2 == 2)) {
                return 1;
            }
            if ((Y2 - Y1 == 1) && (X1 - X2 == 2)) {
                return 1;
            }
            break;
        case 'B':
            if ((stringOfMove[2] == '-') && (desk[Y2][X2] != ' ')) {
                printf("Вроде надо рубить?\n");
                break;
            }
            if (checkDiagonalMove()) {
                return 1;
            }
            break;
        case 'K':
            if ((stringOfMove[2] == '-') && (desk[Y2][X2] != ' ')) {
                printf("Вроде надо рубить?\n");
                break;
            }
            if ((Y1 - Y2 != 1) && (Y2 - Y1 != 1)
                && ((X1 - X2 != 1) && (X2 - X1 != 1))) {
                break;
            } else {
                return 1;
            }
        case 'Q':
            if ((stringOfMove[2] == '-') && (desk[Y2][X2] != ' ')) {
                printf("Вроде надо рубить?\n");
                break;
            }
            if (checkXCoordinateMove() || checkYCoordinateMove() || checkDiagonalMove()) {
                return 1;
            }
            break;
    }

    return 0;
}

int moveBlackFigure(const char stringOfMove[]) {
    if ((desk[Y2][X2] > 'a') && (desk[Y2][X2] < 's')) {
        return 0; //не рубим своих
    }

    switch (desk[Y1][X1]) {
        case 'p':
            if ((stringOfMove[2] == '-') && (desk[Y2][X2] != ' ')) {
                printf("Вроде надо рубить?\n");
                break;
            }
            if ((desk[Y2][X2] == ' ') && (Y1 == 6) && (X1 == X2) && (Y1 - Y2 > 0)
                && (Y1 - Y2 < 3) && checkYCoordinateMove()) {
                return 1; //начальный ход
            }
            if ((desk[Y2][X2] == ' ') && (X2 == X1) && (Y1 - Y2 == 1)) {
                transformPawnToNewFigure();
                return 1; //ход по пустым клеткам
            }
            if ((desk[Y2][X2] < 'S' && desk[Y2][X2] > 'A')
                && ((X1 - X2 == 1) || (X1 - X2 == -1)) && (Y1 - Y2 == 1)) {
                return 1; //рубим чужих
            }
            break;
        case 'r':
            if ((stringOfMove[2] == '-') && (desk[Y2][X2] != ' ')) {
                printf("Вроде надо рубить?\n");
                break;
            }
            if ((Y2 == Y1) && (checkXCoordinateMove())) {
                return 1;
            }
            if ((X2 == X1) && (checkYCoordinateMove())) {
                return 1;
            }
            break;
        case 'n':
            if ((stringOfMove[2] == '-') && (desk[Y2][X2] != ' ')) {
                printf("Вроде надо рубить?\n");
                break;
            }
            if ((Y1 - Y2 == 2) && (X1 - X2 == 1)) {
                return 1;
            }
            if ((Y2 - Y1 == 2) && (X2 - X1 == 1)) {
                return 1;
            }
            if ((Y2 - Y1 == 2) && (X1 - X2 == 1)) {
                return 1;
            }
            if ((Y1 - Y2 == 2) && (X2 - X1 == 1)) {
                return 1;
            }
            if ((Y1 - Y2 == 1) && (X2 - X1 == 2)) {
                return 1;
            }
            if ((Y2 - Y1 == 1) && (X2 - X1 == 2)) {
                return 1;
            }
            if ((Y1 - Y2 == 1) && (X1 - X2 == 2)) {
                return 1;
            }
            if ((Y2 - Y1 == 1) && (X1 - X2 == 2)) {
                return 1;
            }
            break;
        case 'b':
            if ((stringOfMove[2] == '-') && (desk[Y2][X2] != ' ')) {
                printf("Вроде надо рубить?\n");
                break;
            }
            if (checkDiagonalMove()) {
                return 1;
            }
            break;
        case 'k':
            if ((stringOfMove[2] == '-') && (desk[Y2][X2] != ' ')) {
                printf("Вроде надо рубить?\n");
                break;
            }
            if ((Y1 - Y2 != 1) && (Y2 - Y1 != 1)
                && ((X1 - X2 != 1) && (X2 - X1 != 1))) {
                break;
            } else {
                return 1;
            }
        case 'q':
            if ((stringOfMove[2] == '-') && (desk[Y2][X2] != ' ')) {
                printf("Вроде надо рубить?\n");
                break;
            }
            if (checkXCoordinateMove() || checkYCoordinateMove() || checkDiagonalMove()) {
                return 1;
            }
            break;
    }

    return 0;
}

void updateDesk() {
    desk[Y2][X2] = desk[Y1][X1];
    desk[Y1][X1] = ' ';
}

int checkYCoordinateMove() {
    int i, c1 = Y1, c2 = Y2;

    if (X1 != X2) {
        return 0;
    }

    if (Y1 > Y2) {
        c1 = Y2;
        c2 = Y1;
    }
    for (i = c1 + 1; i < c2; i++) {
        if ((desk[i][X1] > 'a' && desk[i][X1] < 's')
            || (desk[i][X1] > 'A' && desk[i][X1] < 'S')) {
            return 0;
        }
    }

    return 1;
}

int checkXCoordinateMove() {
    int i, c1 = X1, c2 = X2;

    if (Y1 != Y2) {
        return 0;
    }

    if (X1 > X2) {
        c1 = X2;
        c2 = X1;
    }
    for (i = c1 + 1; i < c2; i++) {
        if ((desk[Y1][i] > 'a' && desk[Y1][i] < 's')
            || (desk[Y1][i] > 'A' && desk[Y1][i] < 'S')) {
            return 0;
        }
    }

    return 1;
}

int checkDiagonalMove() {
    int i, j, c1 = Y2, c2 = Y1, ci, cj;

    if (((Y2 - Y1) != (X2 - X1)) && ((Y2 - Y1) != (X1 - X2))) {
        return 0;
    }

    if (Y2 > Y1) {
        c1 = Y1;
        c2 = Y2;
        ci = 1;
    } else {
        ci = -1;
    }
    if (X2 > X1) {
        cj = 1;
    } else {
        cj = -1;
    }

    i = Y1 + ci;
    j = X1 + cj;

    while ((i < c2) && (i > c1)) {
        if (((desk[i][j] > 'a') && (desk[i][j] < 's'))
            || ((desk[i][j] > 'A') && (desk[i][j] < 'S'))) {
            return 0;
        }
        i += ci;
        j += cj;
    }

    return 1;
}

void transformPawnToNewFigure() {
    char newPawnFigure;

    if ((desk[Y1][X1] == 'p') && (Y2 == 0)) {
        while (1) {
            printf("Введите в какую фигуру превратить:");
            newPawnFigure = getchar();
            if ((newPawnFigure == 'r') || (newPawnFigure == 'n') || (newPawnFigure == 'b')
                || (newPawnFigure == 'q')) {
                desk[Y1][X1] = newPawnFigure;
                break;
            } else {
                printf("Введите правильную фигуру.\n");
            }
        }
    }
    if ((desk[Y1][X1] == 'P') && (Y2 == 7)) {
        while (1) {
            printf("Введите в какую фигуру превратить:");
            newPawnFigure = getchar();
            if ((newPawnFigure == 'R') || (newPawnFigure == 'N') || (newPawnFigure == 'B')
                || (newPawnFigure == 'Q')) {
                desk[Y1][X1] = newPawnFigure;
                break;
            } else {
                printf("Введите правильную фигуру.\n");
            }
        }
    }
}

int checkWin(int colorOfPlayer) {
    int i, j, winColorOfPlayer = 0;

    if (colorOfPlayer == 1) {
        for (i = 0; i < 8; i++) {
            for (j = 0; j < 8; j++) {
                if (desk[i][j] == 'q') {
                    winColorOfPlayer = 1;
                }
            }
        }
    }
    if (colorOfPlayer == 2) {
        for (i = 0; i < 8; i++) {
            for (j = 0; j < 8; j++) {
                if (desk[i][j] == 'Q') {
                    winColorOfPlayer = 2;
                }
            }
        }
    }

    if (winColorOfPlayer == 0) {
        return colorOfPlayer;
    }

    return 0;
}
