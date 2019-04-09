#ifndef BOARD_H
#define BOARD_H

void scanan();
int chartoint(char input[6]);
int white();
int black();
void move();
int checkY();
int checkX();
int checkD();
void transformPawn();
int checkWIn(int status);

#endif