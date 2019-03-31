#include "board_print_plain.h"
#include <stdio.h>

int x1, x2, y1, y2;
char desk[8][8] = {{'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
                   {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
                   {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                   {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                   {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                   {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                   {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
                   {'R', 'N', 'B', 'K', 'Q', 'B', 'N', 'R'}};

int main()
{
    printdesk();

    scanan();
        
    return 0;
}