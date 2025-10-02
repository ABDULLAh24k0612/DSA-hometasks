#include <iostream>
using namespace std;

#define N 7


int dx[] = {0, 1, 0, -1};  
int dy[] = {1, 0, -1, 0};  


bool isSafe(int maze[N][N], int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1);
}


bool solveMaze(int maze[N][N], int x, int y, int sol[N][N]) {
   
    if (x == N - 1 && y == N - 1) {
        sol[x][y] = 1;
        return true;
    }

    if (isSafe(maze, x, y)) {
        sol[x][y] = 1; 

      
        for (int dir = 0; dir < 4; dir++) {
            int newX = x + dx[dir];
            int newY = y + dy[dir];
            if (solveMaze(maze, newX, newY, sol))
                return true;
        }

      
        sol[x][y] = 0;
        return false;
    }

    return false;
}


void printSolution(int sol[N][N]) {
    cout << "Solution Path (1 = path taken):\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << sol[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
   
    int maze[N][N] = {
        {1, 0, 1, 1, 1, 0, 1},
        {1, 1, 1, 0, 1, 1, 1},
        {0, 0, 1, 0, 1, 0, 0},
        {1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1},
        {0, 0, 0, 0, 0, 0, 1}
    };

    int sol[N][N] = {0}; 

    if (solveMaze(maze, 0, 0, sol)) {
        printSolution(sol);
    } else {
        cout << "No path found to reach the ice cream shop!" << endl;
    }

    return 0;
}
