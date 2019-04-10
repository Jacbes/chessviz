#include "../src/board.h"
#include "../src/board_print_plain.h"
#include "../thirdparty/ctest.h"
#include <stdio.h>
#include <string.h>

int status = 0, i, j;
int X1, X2, Y1, Y2;
char desk[8][8] = {{'R', 'N', 'B', 'K', 'Q', 'B', 'N', 'R'},
                   {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
                   {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                   {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                   {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                   {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                   {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
                   {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}};
char input[7];

CTEST(inputdata, chartointer)
{
    strcpy(input, "E2fE4"); // Ввод неправильного формата
    int c1 = chartoint(input);

    strcpy(input, "E2xE4"); // Ход взятия
    int c2 = chartoint(input);

    strcpy(input, "E2-E4"); // Обычный ход
    int c3 = chartoint(input);

    strcpy(input, "E2-E9"); // Ход за пределы поля
    int c4 = chartoint(input);

    strcpy(input, "hello!"); // Ввод мусора
    int c5 = chartoint(input);

    const int exp1 = 0;
    const int exp2 = 0;
    const int exp3 = 1;
    const int exp4 = 0;
    const int exp5 = 0;

    ASSERT_EQUAL(exp1, c1);
    ASSERT_EQUAL(exp2, c2);
    ASSERT_EQUAL(exp3, c3);
    ASSERT_EQUAL(exp4, c4);
    ASSERT_EQUAL(exp5, c5);
}

CTEST(moving, movewhitepawn) // Тест белой пешки
{
    for (i = 0; i < 8; i++) { // Очистка доски для теста
        for (j = 0; j < 8; j++) {
            desk[i][j] = ' ';
        }
    }

    strcpy(input, "E2-E3"); // Первый ход на одну клетку
    chartoint(input);
    desk[Y1][X1] = 'P';
    int c1 = white();

    strcpy(input, "E2-E4"); // Первый ход на две клетки
    chartoint(input);
    int c2 = white();
    desk[Y1][X1] = ' ';

    strcpy(input, "E3-E5"); // Не первый ход на две клетки
    chartoint(input);
    desk[Y1][X1] = 'P';
    int c3 = white();

    strcpy(input, "E3-F4"); // Ход по диагонали
    chartoint(input);
    int c4 = white();

    strcpy(input, "E3-E2"); // Ход назад
    chartoint(input);
    int c5 = white();

    strcpy(input, "E3xF4"); // Взятие чужих фигуры
    chartoint(input);
    desk[Y2][X2] = 'p';
    int c6 = white();
    desk[Y2][X2] = ' ';
    desk[Y1][X1] = ' ';

    strcpy(input, "E2-E4"); // Первый ход через фигуру
    chartoint(input);
    desk[Y1][X1] = 'P';
    desk[Y1 + 1][X1] = 'p';
    int c7 = white();
    desk[Y1][X1] = ' ';
    desk[Y1 + 1][X1] = ' ';

    const int exp1 = 1;
    const int exp2 = 1;
    const int exp3 = 0;
    const int exp4 = 0;
    const int exp5 = 0;
    const int exp6 = 1;
    const int exp7 = 0;

    ASSERT_EQUAL(exp1, c1);
    ASSERT_EQUAL(exp2, c2);
    ASSERT_EQUAL(exp3, c3);
    ASSERT_EQUAL(exp4, c4);
    ASSERT_EQUAL(exp5, c5);
    ASSERT_EQUAL(exp6, c6);
    ASSERT_EQUAL(exp7, c7);
}

CTEST(moving, moveblackpawn) // Тест черной пешки
{
    strcpy(input, "D7-D6"); // Первый ход на одну клетку
    chartoint(input);
    desk[Y1][X1] = 'p';
    int c1 = black();

    strcpy(input, "D7-D5"); // Первый ход на две клетки
    chartoint(input);
    int c2 = black();
    desk[Y1][X1] = ' ';

    strcpy(input, "D6-D4"); // Не первый ход на две клетки
    chartoint(input);
    desk[Y1][X1] = 'p';
    int c3 = black();

    strcpy(input, "D6-C5"); // Ход по диагонали
    chartoint(input);
    int c4 = black();

    strcpy(input, "D6-D7"); // Ход назад
    chartoint(input);
    int c5 = black();

    strcpy(input, "D6xC5"); // Взятие чужих фигуры
    chartoint(input);
    desk[Y2][X2] = 'P';
    int c6 = black();
    desk[Y2][X2] = ' ';
    desk[Y1][X1] = ' ';

    strcpy(input, "D7-D5"); // Первый ход через фигуру
    chartoint(input);
    desk[Y1][X1] = 'P';
    desk[Y1 + 1][X1] = 'P';
    int c7 = black();
    desk[Y1][X1] = ' ';
    desk[Y1 + 1][X1] = ' ';

    const int exp1 = 1;
    const int exp2 = 1;
    const int exp3 = 0;
    const int exp4 = 0;
    const int exp5 = 0;
    const int exp6 = 1;
    const int exp7 = 0;

    ASSERT_EQUAL(exp1, c1);
    ASSERT_EQUAL(exp2, c2);
    ASSERT_EQUAL(exp3, c3);
    ASSERT_EQUAL(exp4, c4);
    ASSERT_EQUAL(exp5, c5);
    ASSERT_EQUAL(exp6, c6);
    ASSERT_EQUAL(exp7, c7);
}

CTEST(moving, moverook) // Тест ладьи
{
    strcpy(input, "D4-D7"); // Ход вперед
    chartoint(input);
    desk[Y1][X1] = 'R';
    int c1 = white();

    strcpy(input, "D4-D2"); // Ход назад
    chartoint(input);
    int c2 = white();

    strcpy(input, "D4-F4"); // Ход вправо
    chartoint(input);
    int c3 = white();

    strcpy(input, "D4-B4"); // Ход влево
    chartoint(input);
    int c4 = white();

    strcpy(input, "D4-F6"); // Ход по диагонали
    chartoint(input);
    int c5 = white();

    strcpy(input, "D4xD5"); // Взятие чужой клетки
    chartoint(input);
    desk[Y2][X2] = 'r';
    int c6 = white();

    strcpy(input, "D4-D6"); // Ход через фигуру
    chartoint(input);
    int c7 = white();
    desk[Y1][X1] = ' ';
    desk[Y2 - 1][X2] = ' ';

    const int exp1 = 1;
    const int exp2 = 1;
    const int exp3 = 1;
    const int exp4 = 1;
    const int exp5 = 0;
    const int exp6 = 1;
    const int exp7 = 0;

    ASSERT_EQUAL(exp1, c1);
    ASSERT_EQUAL(exp2, c2);
    ASSERT_EQUAL(exp3, c3);
    ASSERT_EQUAL(exp4, c4);
    ASSERT_EQUAL(exp5, c5);
    ASSERT_EQUAL(exp6, c6);
    ASSERT_EQUAL(exp7, c7);
}

CTEST(moving, moveknight) // Тест коня
{
    strcpy(input, "D4-D7"); // Ход вперед
    chartoint(input);
    desk[Y1][X1] = 'N';
    int c1 = white();

    strcpy(input, "D4-D2"); // Ход назад
    chartoint(input);
    int c2 = white();

    strcpy(input, "D4-F4"); // Ход вправо
    chartoint(input);
    int c3 = white();

    strcpy(input, "D4-B4"); // Ход влево
    chartoint(input);
    int c4 = white();

    strcpy(input, "D4-F6"); // Ход по диагонали
    chartoint(input);
    int c5 = white();

    strcpy(input, "D4-C6"); // Ход вверх влево
    chartoint(input);
    int c61 = white();

    strcpy(input, "D4-E6"); // Ход вверх вправо
    chartoint(input);
    int c62 = white();

    strcpy(input, "D4-F5"); // Ход вправо вверх
    chartoint(input);
    int c63 = white();

    strcpy(input, "D4-F3"); // Ход вправо вниз
    chartoint(input);
    int c64 = white();

    strcpy(input, "D4-E2"); // ход вниз вправо
    chartoint(input);
    int c65 = white();

    strcpy(input, "D4-C2"); // Ход вниз влево
    chartoint(input);
    int c66 = white();

    strcpy(input, "D4-B5"); // Ход влево вверх
    chartoint(input);
    int c67 = white();

    strcpy(input, "D4-B3"); // Ход влево вниз
    chartoint(input);
    int c68 = white();

    strcpy(input, "D4xE6"); // Ход через фигуру и взятие
    chartoint(input);
    desk[X1 + 1][Y1] = 'p';
    desk[Y2][X2] = 'n';
    int c7 = white();

    const int exp1 = 0;
    const int exp2 = 0;
    const int exp3 = 0;
    const int exp4 = 0;
    const int exp5 = 0;
    const int exp61 = 1;
    const int exp62 = 1;
    const int exp63 = 1;
    const int exp64 = 1;
    const int exp65 = 1;
    const int exp66 = 1;
    const int exp67 = 1;
    const int exp68 = 1;
    const int exp7 = 1;

    ASSERT_EQUAL(exp1, c1);
    ASSERT_EQUAL(exp2, c2);
    ASSERT_EQUAL(exp3, c3);
    ASSERT_EQUAL(exp4, c4);
    ASSERT_EQUAL(exp5, c5);
    ASSERT_EQUAL(exp61, c61);
    ASSERT_EQUAL(exp62, c62);
    ASSERT_EQUAL(exp63, c63);
    ASSERT_EQUAL(exp64, c64);
    ASSERT_EQUAL(exp65, c65);
    ASSERT_EQUAL(exp66, c66);
    ASSERT_EQUAL(exp67, c67);
    ASSERT_EQUAL(exp68, c68);
    ASSERT_EQUAL(exp7, c7);
}