#include <iostream>
#include <stack>
#include <queue>
#include <unistd.h>
using namespace std;

const int MAZE_ROW_SIZE = 6;
const int MAZE_COL_SIZE = 6;

struct Point
{
    int row;
    int col;
    char type;
    Point(){}
    Point(int row1, int col1, char type1='\0')
    {
        row = row1;
        col = col1;
        type = type1;
    }
};

void displayMaze(char maze[][MAZE_COL_SIZE], int rowSize, int colSize);
bool findPath(char maze[][MAZE_COL_SIZE], int rowSize, int colSize, int row, int col);
bool findPathIt(char maze[][MAZE_COL_SIZE], int rowSize, int colSize, int startRow, int startCol);

int main()
{   
    char maze1[][MAZE_COL_SIZE] = {{'S', '#', '#', '#', '#', '#'},
                                   {'.', '.', '.', '.', '.', '#'},
                                   {'#', '.', '#', '#', '#', '#'},
                                   {'#', '.', '#', '#', '#', '#'},
                                   {'.', '.', '.', '#', '.', 'G'},
                                   {'#', '#', '.', '.', '.', '#'}};
    
    char maze2[][MAZE_COL_SIZE] = {{'S', '.', '#', '#', '#', '#'},
                                   {'#', '.', '#', '.', '.', '#'},
                                   {'#', '.', '#', '.', '.', '#'},
                                   {'#', '.', '.', '.', '.', '#'},
                                   {'#', '#', '#', '.', '.', '.'},
                                   {'G', '.', '.', '.', '#', '#'}};

    char maze3[][MAZE_COL_SIZE] = {{'S', '.', '#', '#', '#', '#'},
                                   {'#', '.', '#', '.', '.', '#'},
                                   {'#', '.', '#', '.', '.', '#'},
                                   {'#', '.', '.', '#', '.', '#'},
                                   {'#', '#', '#', '.', '.', '.'},
                                   {'G', '.', '.', '.', '#', '#'}};

    // findPath(maze1, MAZE_ROW_SIZE, MAZE_COL_SIZE, 0, 0);

    findPathIt(maze2, MAZE_ROW_SIZE, MAZE_COL_SIZE, 0, 0);

    return 0;
}

void displayMaze(char maze[][MAZE_COL_SIZE], int rowSize, int colSize)
{
    system("clear");
    for (int row = 0; row < rowSize; ++row)
    {
        for (int col = 0; col < colSize; ++col)
        {
            cout << maze[row][col];
        }
        cout << '\n';
    }
    usleep(500000);
}

bool findPathIt(char maze[][MAZE_COL_SIZE], int rowSize, int colSize, int startRow, int startCol)
{
    stack<Point> moves;

    int row = startRow;
    int col = startCol;

    maze[row][col] = '+';
    displayMaze(maze, rowSize, colSize);
    moves.push(Point(row, col, '+'));
    moves.push(Point(row-1, col));
    moves.push(Point(row+1, col));
    moves.push(Point(row, col+1));
    moves.push(Point(row, col-1));

    Point pos = moves.top();
    moves.pop();

    while (!moves.empty())
    {
        row = pos.row;
        col = pos.col;

        // outside maze
        if (row < 0 || row >= rowSize || col < 0 || col >= colSize)
        {
            pos = moves.top();
            moves.pop();
        }
        // find goal
        else if (maze[row][col] == 'G')
            return true;
        // not open or wall
        else if (maze[row][col] == '#' || maze[row][col] == '+')
        {
            pos = moves.top();
            moves.pop();
        }
        else
        {
            maze[row][col] = '+';
            displayMaze(maze, rowSize, colSize);
            moves.push(Point(row, col, '+'));
            moves.push(Point(row-1, col));
            moves.push(Point(row+1, col));
            moves.push(Point(row, col+1));
            moves.push(Point(row, col-1));
            pos = moves.top();
            moves.pop();
        }

        if (pos.type == '+')
        {
            maze[pos.row][pos.col] = '.';
            displayMaze(maze, rowSize, colSize);
            pos = moves.top();
            moves.pop();
        }
    }

    return false;
}

bool findPath(char maze[][MAZE_COL_SIZE], int rowSize, int colSize, int row, int col)
{
    // outside maze
    if (row < 0 || row >= rowSize || col < 0 || col >= colSize)
        return false;
    // find goal
    else if (maze[row][col] == 'G')
        return true;
    // not open or wall
    else if (maze[row][col] == '#' || maze[row][col] == '+')
        return false;
    
    // mark x,y as part of solution path
    maze[row][col] = '+';
    displayMaze(maze, rowSize, colSize);

    if (findPath(maze, rowSize, colSize, row, col-1))
        return true; // West
    if (findPath(maze, rowSize, colSize, row, col+1))
        return true; // East
    if (findPath(maze, rowSize, colSize, row+1, col))
        return true; // North
    if (findPath(maze, rowSize, colSize, row-1, col))
        return true; // South

    // unmark x, y as as not part of solution
    maze[row][col] = '.';
    displayMaze(maze, rowSize, colSize);

    return false;
}