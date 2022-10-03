#ifndef BOARD_H
#define BOARD_H

void inputStringOfMove(int colorOfPlayer);
int parseStringOfMoveToCoordinates(const char stringOfMove[]);
int moveWhiteFigure(const char stringOfMove[]);
int moveBlackFigure(const char stringOfMove[]);
void updateDesk();
int checkYCoordinateMove();
int checkXCoordinateMove();
int checkDiagonalMove();
void transformPawnToNewFigure();
int checkWin(int colorOfPlayer);

#endif
