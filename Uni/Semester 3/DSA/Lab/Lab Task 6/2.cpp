#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
          for(int r = 0; r < board.size(); r++) {
            for(int c = 0; c < board[0].size(); c++) {
                if(dfs(board, word, 0, r, c)) return true;
            }
        }
        return false;
    }

     bool dfs(vector<vector<char>>& board, string word, int index, int row, int col) {
        if(index == word.size()){
            return true;
        }

        if(row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || board[row][col] == '0' || board[row][col] != word[index] ){
            return false;
        }

            char s = board[row][col];
            board[row][col] = '0';     
                bool found = dfs(board,word,index+1,row+1,col) || dfs(board,word,index+1,row,col+1) || dfs(board,word,index+1,row-1,col) || dfs(board,word,index+1,row,col-1);
            board[row][col] = s;
            return found;

    }
};

int main() {
    Solution sol;

    vector<vector<char>> board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };

    string word1 = "ABCCED";
    string word2 = "SEE";
    string word3 = "ABCB";

    cout << "Word " << word1 << " exists? " << (sol.exist(board, word1) ? "Yes" : "No") << endl;
    cout << "Word " << word2 << " exists? " << (sol.exist(board, word2) ? "Yes" : "No") << endl;
    cout << "Word " << word3 << " exists? " << (sol.exist(board, word3) ? "Yes" : "No") << endl;

    return 0;
}