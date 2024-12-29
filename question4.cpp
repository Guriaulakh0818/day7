#include <iostream>
#include <vector>

using namespace std;

void solveNQueens(int n, int row, vector<string>& board, vector<vector<string>>& result, vector<int>& leftDiagonal, vector<int>& rightDiagonal, vector<int>& columns) {
    if (row == n) {
        result.push_back(board);
        return;
    }
    
    for (int col = 0; col < n; col++) {
        if (columns[col] == 0 && leftDiagonal[row - col + n - 1] == 0 && rightDiagonal[row + col] == 0) {
            board[row][col] = 'Q';
            columns[col] = 1;
            leftDiagonal[row - col + n - 1] = 1;
            rightDiagonal[row + col] = 1;
            
            solveNQueens(n, row + 1, board, result, leftDiagonal, rightDiagonal, columns);
            
            board[row][col] = '.';
            columns[col] = 0;
            leftDiagonal[row - col + n - 1] = 0;
            rightDiagonal[row + col] = 0;
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> result;
    vector<string> board(n, string(n, '.'));
    vector<int> leftDiagonal(2 * n - 1, 0);
    vector<int> rightDiagonal(2 * n - 1, 0);
    vector<int> columns(n, 0);
    
    solveNQueens(n, 0, board, result, leftDiagonal, rightDiagonal, columns);
    return result;
}

int main() {
    int n = 4; 
    vector<vector<string>> solutions = solveNQueens(n);
    
    for (const auto& solution : solutions) {
        for (const auto& row : solution) {
            cout << row << endl;
        }
        cout << endl;
    }
    
    return 0;
}
