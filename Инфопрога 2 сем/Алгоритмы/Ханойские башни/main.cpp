#include <iostream>

using namespace std;

void showBoard(int board[5][3],  int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (board[i][j] == 0)
            {
                std::cout << " \t";
            }

            else
            {
                std::cout << board[i][j] << "\t";
            }
        }
        
        std::cout << std::endl;
    }

    std::cout << "\n\n";
}

int getRow(int board[5][3], int rows, int nCol)
{
    int nRow = -1;

    for (int i = 0; i < rows; i++)
    {
        if (board[i][nCol] != 0)
        {
            nRow = i;

            break;
        }
    }

    return nRow;
}

void move(char point1, char point2, int board[5][3], int rows, int cols)
{
    int col1 = (int)point1 - (int)'A';
    int col2 = (int)point2 - (int)'A';

    int row1 = getRow(board, rows, col1);
    int row2 = getRow(board, rows, col2);

    if (row2 == -1)
    {
        row2 = rows - 1;
    }

    else
    {
        row2--;
    }

    int value = board[row1][col1];

    board[row1][col1] = 0;
    board[row2][col2] = value;

    showBoard(board, rows, cols);
}

bool isEmpty(int board[5][3], int rows, int cols)
{
    int lastRowIndex = rows - 1;
    
    for (int j = 0; j < cols; j++)
    {
        if (board[lastRowIndex][j] != 0)
        {
            return false;
        }
    }

    return true;
}

void initBoard(int diskCount, int board[5][3], int rows, nCol)
{
    int lastRowIndex = rows - 1;

    for (int i = lastRowIndex; diskCount > 0; i --)
    {
        board[i][nCol] = diskCount;

        diskCount --;
    }
}

void moveTower(int amount, char point1, char, point2, char temp, int board[5][3], int rows, int cols)
{
    if (amount == 0)
    {
        return;
    }

    if (isEmpty(board, rows, cols))
    {
        initBoard(amount, board, rows, 0);

        std::cout << "Исходная позиция" << std::endl;

        showBoard(board, rows, cols);
    }

    moveTower(amount - 1, temp, point1, point2, board, rows, cols);
    
    move(point1, point2, board, rows, cols);

    moveTower(amount - 1, temp, point2, point1, board, rows, cols);
}

int main()
{
    const int rows = 5;
    const int cols = 3;

    int board[rows][cols] = {0};

    moveTower(5, 'A', 'B', 'C', board, rows, cols);
}
