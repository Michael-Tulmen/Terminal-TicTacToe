#include <stdio.h>
#include <string.h>

void displayBoard(char board[3][3]);
int checkWin(char board[3][3], char player);
int checkDraw(char board[3][3]);
void takeTurn(char board[3][3], char player);

int main(void)
{
    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };

    char currentPlayer = 'X';

    printf("Tic Tac Toe\n");

    while (1)
    {
        displayBoard(board);
        printf("Player %c's turn - Enter row and column (0-2): ", currentPlayer);
        takeTurn(board, currentPlayer);

        if (checkWin(board, currentPlayer))
        {
            displayBoard(board);
            printf("Player %c wins!\n", currentPlayer);
            break;
        }

        if (checkDraw(board))
        {
            displayBoard(board);
            printf("It's a draw!\n");
            break;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}

void displayBoard(char board[3][3])
{
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
}

int checkWin(char board[3][3], char p)
{
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == p && board[i][1] == p && board[i][2] == p) return 1;
        if (board[0][i] == p && board[1][i] == p && board[2][i] == p) return 1;
    }
    if (board[0][0] == p && board[1][1] == p && board[2][2] == p) return 1;
    if (board[0][2] == p && board[1][1] == p && board[2][0] == p) return 1;
    return 0;
}

int checkDraw(char board[3][3])
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == ' ') return 0;
    return 1;
}

void takeTurn(char board[3][3], char player)
{
    int row, col;
    scanf("%d %d", &row, &col);

    if (row < 0 || row > 2 || col < 0 || col > 2)
    {
        printf("Invalid position. Try again: ");
        takeTurn(board, player);
        return;
    }

    if (board[row][col] != ' ')
    {
        printf("Cell already occupied. Try again: ");
        takeTurn(board, player);
        return;
    }

    board[row][col] = player;
}