#include "board.h"
#include "board_print_plain.h"
#include <stdio.h>

int main()
{
    int status = 0;

    printf("     Шахматы\n");
    printf("Пример обычного хода: E2-E4\n");
    printf("Пример хода взятия: E2xE4\n");

    printdesk();

    while (1) {
        printf("Белые (Большие буквы):");
        scanan(1);
        move();
        printdesk();
        status = checkWIn(1);
        if (status != 0) {
            break;
        }

        printf("Черные (Маленькие буквы):");
        scanan(2);
        move();
        printdesk();
        status = checkWIn(2);
        if (status != 0) {
            break;
        }
    }

    printf("Player %d win\n", status);

    return 0;
}