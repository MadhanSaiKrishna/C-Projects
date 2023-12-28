#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#include "functions.h"

int main()
{
    char **board = (char **)malloc(3 * sizeof(char *));
    for (int i = 0; i < 3; i++)
    {
        board[i] = (char *)malloc(3 * sizeof(char));
    }
    char winner = ' ';
    char response;
    do
    {
        winner = ' ';
        response= ' ';
        resetBoard(board);
        while (winner == ' ' && checkFreeSpaces(board) != 0)
        {
            printBoard(board);

            playerMove(board);
            winner = checkWinner(board);
            if (winner != ' ' || checkFreeSpaces(board) == 0)
            {
                break;
            }
            computerMove(board);
            winner = checkWinner(board);
            if (winner != ' ' || checkFreeSpaces(board) == 0)
            {
                break;
            }
        }
        printBoard(board);
        printWinner(winner);
        printf("\n Would you like to play again? (Y/N): ");
        scanf("%c");
        scanf("%c", &response);
        response= toupper(response);
    } while (response=='Y');

    printf("Thanks for playing! \n");

    return 0;
}