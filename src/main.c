#include "board.h"
#include "board_print_plain.h"
#include <stdio.h>

int main()
{
    printdesk();
    while (1) {
        printf("Белые (Большие буквы):");
        scanan(1);
        move();
        printdesk();
        printf("Черные (Маленькие буквы):");
        scanan(2);
        move();
        printdesk();
    }
    return 0;
}