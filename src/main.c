#include "board.h"
#include "board_print_plain.h"
#include <stdio.h>

int main()
{
    printf("     Шахматы\n");
    printf("Пример обычного хода: E2-E4\n");
    printf("Пример хода взятия: E2xE4\n");
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