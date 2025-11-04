#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool safe(vector<string>& matrix, int row, int col, int n) {
        for (int i = 0; i < row; i++) {
            if (matrix[i][col] == 'Q') {
                return false;
            }
        }
        for (int j = 0; j < col; j++) {
            if (matrix[row][j] == 'Q') {
                return false;
            }
        }
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (matrix[i][j] == 'Q') {
                return false;
            }
        }
        for (int i = row, j = col; i>=0 && j < n; i--, j++) {
            if (matrix[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }

    void setQueens(vector<string>& matrix, int row, int n, vector<vector<string>>& r) {
        if (row == n) {
            r.push_back({matrix});
            return;
        }
        for (int i = 0; i < n; i++) {
            if (safe(matrix, row, i, n)) {
                matrix[row][i] = 'Q';
                setQueens(matrix, row + 1, n, r);
                matrix[row][i] = '.'; // Backtrack
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> r;
        vector<string> matrix(n, string(n, '.'));
        setQueens(matrix, 0, n, r);
        return r;
    }
};
int main() {
    Solution s;
    auto result = s.solveNQueens(4);
    for (auto &board : result) {
        for (auto &row : board) {
            cout << row << endl;
        }
        cout << endl;
    }
}

