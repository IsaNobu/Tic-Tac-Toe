#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

char board[3][3];
const char PLAYER = 'x';
const char COMPUTER = 'O';

void resetBoard();
void printBoard();
void playerMove();
void computerMove();
void printWinner(char);
int checkFreeSpace();
char checkWinner();

int main()
{
    char winner = ' ';

    resetBoard();
    while (winner == ' ' && checkFreeSpace() != 0)
    {
        printBoard();

        playerMove();
        winner = checkWinner();

        if (winner != ' ' || checkFreeSpace() == 0)
        {
            break;
        }

        computerMove();
        winner = checkWinner();

        if (winner != ' ' || checkFreeSpace() == 0)
        {
            break;
        }
    }

    printWinner(winner);

    return 0;
};

void printBoard()
{

    printf(" %c | %c | %c ", board[0][0], board[0][1], board[0][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[1][0], board[1][1], board[1][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[2][0], board[2][1], board[2][2]);
    printf("\n");
};

void resetBoard()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = ' ';
        }
    }
};

void playerMove()
{
    int x;
    int y;

    do
    {
        printf("Enter row #(1-3): ");
        scanf("%d", &x);
        x--;

        printf("Enter column #(1-3): ");
        scanf("%d", &y);
        y--;

        if (board[x][y] != ' ')
        {
            printf("Invalid Move\n");
        }
        else
        {
            board[x][y] = PLAYER;
            break;
        }
    } while (board[x][y] != ' ');
};

void computerMove()
{
    srand(time(0));
    int x;
    int y;

    if (checkFreeSpace() > 0)
    {
        do
        {
            x = rand() % 3;
            y = rand() % 3;

        } while (board[x][y] != ' ');

        board[x][y] = COMPUTER;
    }
    else
    {
        printWinner(' ');
    }
}

void printWinner(char winner)
{
    if (winner == PLAYER)
    {
        printf("You Win");
    }
    else if (winner == COMPUTER)
    {
        printf("You Lose");
    }
    else
    {
        printf("Tie lil bro");
    }
};

int checkFreeSpace()
{
    int freeSpaces = 9;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] != ' ')
            {
                freeSpaces--;
            }
        }
    }

    return freeSpaces;
};

char checkWinner()
{
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][2] == board[i][0])
        {
            return board[i][0];
        }
    }

    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == board[1][i] && board[2][i] == board[1][i])
        {
            return board[0][i];
        }
    }

    if (board[0][0] == board[1][1] && board[0][0] == board[2][2])
    {
        return board[0][0];
    }
    if (board[0][2] == board[1][1] && board[0][2] == board[2][0])
    {
        return board[0][0];
    }

    return ' ';
};
