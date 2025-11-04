#include<iostream>
#include<vector>
using namespace std;

void findPaths(vector<vector<int>>& maze, int row, int col, int n, vector<string>& result, string path) {
    if (row == n-1 && col == n-1) {
        result.push_back(path);
        return;
    }
    
    maze[row][col] = 0;
    
    if (row + 1 < n && maze[row + 1][col] == 1) {
        findPaths(maze, row + 1, col, n, result, path + "D");
    }
    if (col + 1 < n && maze[row][col + 1] == 1) {
        findPaths(maze, row, col + 1, n, result, path + "R");
    }
    if (row - 1 >= 0 && maze[row - 1][col] == 1) {
        findPaths(maze, row - 1, col, n, result, path + "U");
    }
    if (col - 1 >= 0 && maze[row][col - 1] == 1) {
        findPaths(maze, row, col - 1, n, result, path + "L");
    }
    
    maze[row][col] = 1;
}

int main() {
    vector<vector<int>> maze = {
        {1, 0, 0, 1},
        {1, 1, 0, 0},
        {1, 0, 1, 0},
        {1, 1, 1, 1}
    };
    
    vector<string> result;
    
    if (maze[0][0] == 1) { 
        findPaths(maze, 0, 0, 4, result, "");
    }
    
    cout << "Number of paths: " << result.size() << endl;
    cout << "Paths: ";
    for (string path : result) {
        cout << path << " ";
    }
    
    return 0;
}