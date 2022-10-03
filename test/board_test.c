#include "../src/board.h"
#include "../thirdparty/ctest.h"
#include "../src/board_print_plain.h"
#include <string.h>

int i;
int X1, X2, Y1, Y2;
char desk[8][8] = {{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                   {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                   {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                   {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                   {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                   {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                   {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                   {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}};

CTEST(inputdata, chartointer) {
    char stringOfMove[7];

    strcpy(stringOfMove, "E2fE4"); // Ввод неправильного формата
    int c1 = parseStringOfMoveToCoordinates(stringOfMove);

    strcpy(stringOfMove, "E2xE4"); // Ход взятия
    int c2 = parseStringOfMoveToCoordinates(stringOfMove);

    strcpy(stringOfMove, "E2-E4"); // Обычный ход
    int c3 = parseStringOfMoveToCoordinates(stringOfMove);

    strcpy(stringOfMove, "E2-E9"); // Ход за пределы поля
    int c4 = parseStringOfMoveToCoordinates(stringOfMove);

    strcpy(stringOfMove, "hello!"); // Ввод мусора
    int c5 = parseStringOfMoveToCoordinates(stringOfMove);

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

CTEST(moving, movewhitepawn) { // Тест белой пешки
    char stringOfMove[7];

    strcpy(stringOfMove, "E2-E3"); // Первый ход на одну клетку
    parseStringOfMoveToCoordinates(stringOfMove);
    desk[Y1][X1] = 'P';
    int c1 = moveWhiteFigure(stringOfMove);

    strcpy(stringOfMove, "E2-E4"); // Первый ход на две клетки
    parseStringOfMoveToCoordinates(stringOfMove);
    int c2 = moveWhiteFigure(stringOfMove);

    desk[Y1][X1] = ' ';

    strcpy(stringOfMove, "E3-E5"); // Не первый ход на две клетки
    parseStringOfMoveToCoordinates(stringOfMove);
    desk[Y1][X1] = 'P';
    int c3 = moveWhiteFigure(stringOfMove);

    strcpy(stringOfMove, "E3-F4"); // Ход по диагонали
    parseStringOfMoveToCoordinates(stringOfMove);
    int c4 = moveWhiteFigure(stringOfMove);

    strcpy(stringOfMove, "E3-E2"); // Ход назад
    parseStringOfMoveToCoordinates(stringOfMove);
    int c5 = moveWhiteFigure(stringOfMove);

    strcpy(stringOfMove, "E3xF4"); // Взятие чужой фигуры
    parseStringOfMoveToCoordinates(stringOfMove);
    desk[Y2][X2] = 'p';
    int c6 = moveWhiteFigure(stringOfMove);

    desk[Y2][X2] = ' ';
    desk[Y1][X1] = ' ';

    strcpy(stringOfMove, "E2-E4"); // Первый ход через фигуру
    parseStringOfMoveToCoordinates(stringOfMove);
    desk[Y1][X1] = 'P';
    desk[Y1 + 1][X1] = 'p';
    int c7 = moveWhiteFigure(stringOfMove);

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

CTEST(moving, moveblackpawn) { // Тест черной пешки
    char stringOfMove[7];

    strcpy(stringOfMove, "D7-D6"); // Первый ход на одну клетку
    parseStringOfMoveToCoordinates(stringOfMove);
    desk[Y1][X1] = 'p';
    int c1 = moveBlackFigure(stringOfMove);

    strcpy(stringOfMove, "D7-D5"); // Первый ход на две клетки
    parseStringOfMoveToCoordinates(stringOfMove);
    int c2 = moveBlackFigure(stringOfMove);

    desk[Y1][X1] = ' ';

    strcpy(stringOfMove, "D6-D4"); // Не первый ход на две клетки
    parseStringOfMoveToCoordinates(stringOfMove);
    desk[Y1][X1] = 'p';
    int c3 = moveBlackFigure(stringOfMove);

    strcpy(stringOfMove, "D6-C5"); // Ход по диагонали
    parseStringOfMoveToCoordinates(stringOfMove);
    int c4 = moveBlackFigure(stringOfMove);

    strcpy(stringOfMove, "D6-D7"); // Ход назад
    parseStringOfMoveToCoordinates(stringOfMove);
    int c5 = moveBlackFigure(stringOfMove);

    strcpy(stringOfMove, "D6xC5"); // Взятие чужой фигуры
    parseStringOfMoveToCoordinates(stringOfMove);
    desk[Y2][X2] = 'P';
    int c6 = moveBlackFigure(stringOfMove);

    desk[Y2][X2] = ' ';
    desk[Y1][X1] = ' ';

    strcpy(stringOfMove, "D7-D5"); // Первый ход через фигуру
    parseStringOfMoveToCoordinates(stringOfMove);
    desk[Y1][X1] = 'P';
    desk[Y1 + 1][X1] = 'P';
    int c7 = moveBlackFigure(stringOfMove);

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

CTEST(moving, moverook) { // Тест ладьи
    char stringOfMove[7];

    strcpy(stringOfMove, "D4-D7"); // Ход вперед
    parseStringOfMoveToCoordinates(stringOfMove);
    desk[Y1][X1] = 'R';
    int c1 = moveWhiteFigure(stringOfMove);

    strcpy(stringOfMove, "D4-D2"); // Ход назад
    parseStringOfMoveToCoordinates(stringOfMove);
    int c2 = moveWhiteFigure(stringOfMove);

    strcpy(stringOfMove, "D4-F4"); // Ход вправо
    parseStringOfMoveToCoordinates(stringOfMove);
    int c3 = moveWhiteFigure(stringOfMove);

    strcpy(stringOfMove, "D4-B4"); // Ход влево
    parseStringOfMoveToCoordinates(stringOfMove);
    int c4 = moveWhiteFigure(stringOfMove);

    strcpy(stringOfMove, "D4-F6"); // Ход по диагонали
    parseStringOfMoveToCoordinates(stringOfMove);
    int c5 = moveWhiteFigure(stringOfMove);

    strcpy(stringOfMove, "D4xD5"); // Взятие чужой фигуры
    parseStringOfMoveToCoordinates(stringOfMove);
    desk[Y2][X2] = 'r';
    int c6 = moveWhiteFigure(stringOfMove);

    strcpy(stringOfMove, "D4-D6"); // Ход через фигуру
    parseStringOfMoveToCoordinates(stringOfMove);
    int c7 = moveWhiteFigure(stringOfMove);

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

CTEST(moving, moveknight) { // Тест коня
    char stringOfMove[7];

    strcpy(stringOfMove, "D4-D7"); // Ход вперед
    parseStringOfMoveToCoordinates(stringOfMove);
    desk[Y1][X1] = 'N';
    int c1 = moveWhiteFigure(stringOfMove);

    strcpy(stringOfMove, "D4-D2"); // Ход назад
    parseStringOfMoveToCoordinates(stringOfMove);
    int c2 = moveWhiteFigure(stringOfMove);

    strcpy(stringOfMove, "D4-F4"); // Ход вправо
    parseStringOfMoveToCoordinates(stringOfMove);
    int c3 = moveWhiteFigure(stringOfMove);

    strcpy(stringOfMove, "D4-B4"); // Ход влево
    parseStringOfMoveToCoordinates(stringOfMove);
    int c4 = moveWhiteFigure(stringOfMove);

    strcpy(stringOfMove, "D4-F6"); // Ход по диагонали
    parseStringOfMoveToCoordinates(stringOfMove);
    int c5 = moveWhiteFigure(stringOfMove);

    strcpy(stringOfMove, "D4-C6"); // Ход Г вверх влево
    parseStringOfMoveToCoordinates(stringOfMove);
    int c61 = moveWhiteFigure(stringOfMove);

    strcpy(stringOfMove, "D4-E6"); // Ход Г вверх вправо
    parseStringOfMoveToCoordinates(stringOfMove);
    int c62 = moveWhiteFigure(stringOfMove);

    strcpy(stringOfMove, "D4-F5"); // Ход Г вправо вверх
    parseStringOfMoveToCoordinates(stringOfMove);
    int c63 = moveWhiteFigure(stringOfMove);

    strcpy(stringOfMove, "D4-F3"); // Ход Г вправо вниз
    parseStringOfMoveToCoordinates(stringOfMove);
    int c64 = moveWhiteFigure(stringOfMove);

    strcpy(stringOfMove, "D4-E2"); // Ход Г вниз вправо
    parseStringOfMoveToCoordinates(stringOfMove);
    int c65 = moveWhiteFigure(stringOfMove);

    strcpy(stringOfMove, "D4-C2"); // Ход Г вниз влево
    parseStringOfMoveToCoordinates(stringOfMove);
    int c66 = moveWhiteFigure(stringOfMove);

    strcpy(stringOfMove, "D4-B5"); // Ход Г влево вверх
    parseStringOfMoveToCoordinates(stringOfMove);
    int c67 = moveWhiteFigure(stringOfMove);

    strcpy(stringOfMove, "D4-B3"); // Ход Г влево вниз
    parseStringOfMoveToCoordinates(stringOfMove);
    int c68 = moveWhiteFigure(stringOfMove);

    strcpy(stringOfMove, "D4xE6"); // Ход через фигуру и взятие
    parseStringOfMoveToCoordinates(stringOfMove);
    desk[X1 + 1][Y1] = 'p';
    desk[Y2][X2] = 'n';
    int c7 = moveWhiteFigure(stringOfMove);

    desk[Y1][X1] = ' ';
    desk[X1 + 1][Y1] = ' ';
    desk[Y2][X2] = ' ';

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

CTEST(moving, movebishop) { // Тест слона
    char stringOfMove[7];

    strcpy(stringOfMove, "D4-D7"); // Ход вперед
    parseStringOfMoveToCoordinates(stringOfMove);
    desk[Y1][X1] = 'B';
    int c1 = moveWhiteFigure(stringOfMove);

    strcpy(stringOfMove, "D4-D2"); // Ход назад
    parseStringOfMoveToCoordinates(stringOfMove);
    int c2 = moveWhiteFigure(stringOfMove);

    strcpy(stringOfMove, "D4-F4"); // Ход вправо
    parseStringOfMoveToCoordinates(stringOfMove);
    int c3 = moveWhiteFigure(stringOfMove);

    strcpy(stringOfMove, "D4-B4"); // Ход влево
    parseStringOfMoveToCoordinates(stringOfMove);
    int c4 = moveWhiteFigure(stringOfMove);

    strcpy(stringOfMove, "D4-F6"); // Ход по диагонали вверх вправо
    parseStringOfMoveToCoordinates(stringOfMove);
    int c51 = moveWhiteFigure(stringOfMove);

    strcpy(stringOfMove, "D4-B6"); // Ход по диагонали вверх влево
    parseStringOfMoveToCoordinates(stringOfMove);
    int c52 = moveWhiteFigure(stringOfMove);

    strcpy(stringOfMove, "D4-F2"); // Ход по диагонали вниз вправо
    parseStringOfMoveToCoordinates(stringOfMove);
    int c53 = moveWhiteFigure(stringOfMove);

    strcpy(stringOfMove, "D4xB2"); // Ход по диагонали вверх вправо и взятие
    parseStringOfMoveToCoordinates(stringOfMove);
    desk[Y2][X2] = 'p';
    int c54 = moveWhiteFigure(stringOfMove);

    desk[Y2][X2] = ' ';

    strcpy(stringOfMove, "D4-F6"); // Ход по диагонали вниз вправо через фигуру
    parseStringOfMoveToCoordinates(stringOfMove);
    desk[Y2 - 1][X2 - 1] = 'p';
    int c6 = moveWhiteFigure(stringOfMove);

    desk[Y1][X1] = ' ';
    desk[Y2 - 1][X2 - 1] = ' ';

    const int exp1 = 0;
    const int exp2 = 0;
    const int exp3 = 0;
    const int exp4 = 0;
    const int exp51 = 1;
    const int exp52 = 1;
    const int exp53 = 1;
    const int exp54 = 1;
    const int exp6 = 0;

    ASSERT_EQUAL(exp1, c1);
    ASSERT_EQUAL(exp2, c2);
    ASSERT_EQUAL(exp3, c3);
    ASSERT_EQUAL(exp4, c4);
    ASSERT_EQUAL(exp51, c51);
    ASSERT_EQUAL(exp52, c52);
    ASSERT_EQUAL(exp53, c53);
    ASSERT_EQUAL(exp54, c54);
    ASSERT_EQUAL(exp6, c6);
}

CTEST(moving, moveking) { // Тест короля
    char stringOfMove[7];

    strcpy(stringOfMove, "D4-D5"); // Ход вверх
    parseStringOfMoveToCoordinates(stringOfMove);
    desk[Y1][X1] = 'K';
    int c1 = moveWhiteFigure(stringOfMove);

    strcpy(stringOfMove, "D4-D3"); // Ход вниз
    parseStringOfMoveToCoordinates(stringOfMove);
    int c2 = moveWhiteFigure(stringOfMove);

    strcpy(stringOfMove, "D4-C4"); // Ход влево
    parseStringOfMoveToCoordinates(stringOfMove);
    int c3 = moveWhiteFigure(stringOfMove);

    strcpy(stringOfMove, "D4-E4"); // Ход вправо
    parseStringOfMoveToCoordinates(stringOfMove);
    int c4 = moveWhiteFigure(stringOfMove);

    strcpy(stringOfMove, "D4-E5"); // Ход вверх вправо
    parseStringOfMoveToCoordinates(stringOfMove);
    int c5 = moveWhiteFigure(stringOfMove);

    strcpy(stringOfMove, "D4-C5"); // Ход вверх влево
    parseStringOfMoveToCoordinates(stringOfMove);
    int c6 = moveWhiteFigure(stringOfMove);

    strcpy(stringOfMove, "D4-E3"); // Ход вниз вправо
    parseStringOfMoveToCoordinates(stringOfMove);
    int c7 = moveWhiteFigure(stringOfMove);

    strcpy(stringOfMove, "D4xC3"); // Ход вниз влево и взятие
    parseStringOfMoveToCoordinates(stringOfMove);
    desk[Y2][X2] = 'p';
    int c8 = moveWhiteFigure(stringOfMove);

    desk[Y2][X2] = ' ';

    strcpy(stringOfMove, "D4-D6"); // Ход вверх на 2 клетки
    parseStringOfMoveToCoordinates(stringOfMove);
    int c9 = moveWhiteFigure(stringOfMove);

    strcpy(stringOfMove, "D4-F2"); // Ход вниз вправо на 2 клетки
    parseStringOfMoveToCoordinates(stringOfMove);
    int c10 = moveWhiteFigure(stringOfMove);

    desk[Y1][X1] = ' ';

    const int exp1 = 1;
    const int exp2 = 1;
    const int exp3 = 1;
    const int exp4 = 1;
    const int exp5 = 1;
    const int exp6 = 1;
    const int exp7 = 1;
    const int exp8 = 1;
    const int exp9 = 0;
    const int exp10 = 0;

    ASSERT_EQUAL(exp1, c1);
    ASSERT_EQUAL(exp2, c2);
    ASSERT_EQUAL(exp3, c3);
    ASSERT_EQUAL(exp4, c4);
    ASSERT_EQUAL(exp5, c5);
    ASSERT_EQUAL(exp6, c6);
    ASSERT_EQUAL(exp7, c7);
    ASSERT_EQUAL(exp8, c8);
    ASSERT_EQUAL(exp9, c9);
    ASSERT_EQUAL(exp10, c10);
}

CTEST(moving, movequeen) { // Тест ферзя
    char stringOfMove[7];

    strcpy(stringOfMove, "D4-D7"); // Ход вверх
    parseStringOfMoveToCoordinates(stringOfMove);
    desk[Y1][X1] = 'Q';
    int c1 = moveWhiteFigure(stringOfMove);

    strcpy(stringOfMove, "D4-D1"); // Ход вниз
    parseStringOfMoveToCoordinates(stringOfMove);
    int c2 = moveWhiteFigure(stringOfMove);

    strcpy(stringOfMove, "D4-A4"); // Ход влево
    parseStringOfMoveToCoordinates(stringOfMove);
    int c3 = moveWhiteFigure(stringOfMove);

    strcpy(stringOfMove, "D4-G4"); // Ход вправо
    parseStringOfMoveToCoordinates(stringOfMove);
    int c4 = moveWhiteFigure(stringOfMove);

    strcpy(stringOfMove, "D4-G7"); // Ход по диагонали вверх вправо
    parseStringOfMoveToCoordinates(stringOfMove);
    int c5 = moveWhiteFigure(stringOfMove);

    strcpy(stringOfMove, "D4-A7"); // Ход по диагонали вверх влево
    parseStringOfMoveToCoordinates(stringOfMove);
    int c6 = moveWhiteFigure(stringOfMove);

    strcpy(stringOfMove, "D4-A1"); // Ход по диагонали вних влево
    parseStringOfMoveToCoordinates(stringOfMove);
    int c7 = moveWhiteFigure(stringOfMove);

    strcpy(stringOfMove, "D4xG1"); // Ход по диагонали вниз вправо и взятие
    parseStringOfMoveToCoordinates(stringOfMove);
    desk[Y2][X2] = 'p';
    int c8 = moveWhiteFigure(stringOfMove);

    desk[Y2][X2] = ' ';

    strcpy(stringOfMove, "D4-G7"); // Ход по диагонали вверх вправо через фигуру
    parseStringOfMoveToCoordinates(stringOfMove);
    desk[Y2 - 1][X2 - 1] = 'p';
    int c9 = moveWhiteFigure(stringOfMove);

    desk[Y2 - 1][X2 - 1] = ' ';

    strcpy(stringOfMove, "D4-F7"); // Ход Г по диагонали вверх вправо
    parseStringOfMoveToCoordinates(stringOfMove);
    int c10 = moveWhiteFigure(stringOfMove);

    desk[Y1][X1] = ' ';

    const int exp1 = 1;
    const int exp2 = 1;
    const int exp3 = 1;
    const int exp4 = 1;
    const int exp5 = 1;
    const int exp6 = 1;
    const int exp7 = 1;
    const int exp8 = 1;
    const int exp9 = 0;
    const int exp10 = 0;

    ASSERT_EQUAL(exp1, c1);
    ASSERT_EQUAL(exp2, c2);
    ASSERT_EQUAL(exp3, c3);
    ASSERT_EQUAL(exp4, c4);
    ASSERT_EQUAL(exp5, c5);
    ASSERT_EQUAL(exp6, c6);
    ASSERT_EQUAL(exp7, c7);
    ASSERT_EQUAL(exp8, c8);
    ASSERT_EQUAL(exp9, c9);
    ASSERT_EQUAL(exp10, c10);
}
