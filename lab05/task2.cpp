#include <iostream>
using namespace std;

#define N 5


void printSolution(int solution[N][N]) {
    cout << "Solution Path:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << solution[i][j] << " ";
        }
        cout << endl;
    }
}


bool isSafe(int maze[N][N], int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1);
}


bool solveMazeUtil(int maze[N][N], int x, int y, int solution[N][N]) {
    // If destination is reached
    if (x == N - 1 && y == N - 1) {
        solution[x][y] = 1;
        return true;
    }

    
    if (isSafe(maze, x, y)) {
        solution[x][y] = 1;  

        
        if (solveMazeUtil(maze, x, y + 1, solution))
            return true;

        
        if (solveMazeUtil(maze, x + 1, y, solution))
            return true;

       
        if (solveMazeUtil(maze, x, y - 1, solution))
            return true;

       
        if (solveMazeUtil(maze, x - 1, y, solution))
            return true;

        // Backtrack: Unmark cell
        solution[x][y] = 0;
        return false;
    }

    return false;
}


void solveMaze(int maze[N][N]) {
    int solution[N][N] = { {0} };

    if (solveMazeUtil(maze, 0, 0, solution) == false) {
        cout << "No path to the meat found!" << endl;
    } else {
        printSolution(solution);
    }
}


int main() {
    
    int maze[N][N] = {
        {1, 0, 1, 1, 1},
        {1, 1, 1, 0, 1},
        {0, 0, 0, 1, 1},
        {1, 1, 1, 0, 0},
        {0, 0, 1, 1, 1}
    };

    solveMaze(maze);

    return 0;
}
