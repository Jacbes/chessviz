#ifndef BOARD_H
#define BOARD_H

char input[7];

void scanan();
int chartoint(char input[6]);
int white();
int black();
void move();
int checkY();
int checkX();
int checkD();
void transformPawn();

#endif