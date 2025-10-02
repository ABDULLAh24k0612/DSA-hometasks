#include <iostream>
using namespace std;

#define MAX 20 

int totalSolutions = 0;


void printBoard(int board[MAX][MAX], int N) {
    cout << "One valid board configuration:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j])
                cout << "Q ";
            else
                cout << ". ";
        }
        cout << endl;
    }
    cout << endl;
}

// Function to check if placing a queen at board[row][col] is safe
bool isSafe(int board[MAX][MAX], int row, int col, int N) {
    // Check this column on upper rows
    for (int i = 0; i < row; i++)
        if (board[i][col])
            return false;

   
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

   
    for (int i = row, j = col; i >= 0 && j < N; i--, j++)
        if (board[i][j])
            return false;

    return true;
}


bool solveNQueens(int board[MAX][MAX], int row, int N, bool &firstSolutionPrinted) {
    if (row == N) {
        totalSolutions++;

       
        if (!firstSolutionPrinted) {
            printBoard(board, N);
            firstSolutionPrinted = true;
        }
        return false; 
    }

    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col, N)) {
            board[row][col] = 1;

           
            solveNQueens(board, row + 1, N, firstSolutionPrinted);

            
            board[row][col] = 0;
        }
    }

    return false;
}


int main() {
    int N;
    cout << "Enter the value of N for N-Queens: ";
    cin >> N;

    if (N < 1 || N > MAX) {
        cout << "Please enter N between 1 and " << MAX << endl;
        return 0;
    }

    int board[MAX][MAX] = {0};
    bool firstSolutionPrinted = false;

    solveNQueens(board, 0, N, firstSolutionPrinted);

    cout << "Total number of distinct solutions for N = " << N << " is: " << totalSolutions << endl;

    return 0;
}
