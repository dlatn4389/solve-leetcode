#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int rowsize, colsize;
    bool check = false;

    void func(int row, int col, int chosen, string word, vector<vector<bool>>& visited, vector<vector<char>>& board) {
        if (chosen==word.size()) {
            check = true;
            return;
        }

        if (row<0 or col<0 or row>=rowsize or col>=colsize) return;
        if (visited[row][col]) return;

        if (board[row][col]!=word[chosen]) return;
        visited[row][col] = true;
        func(row+1, col, chosen+1, word, visited, board);
        func(row, col+1, chosen+1, word, visited, board);
        func(row-1, col, chosen+1, word, visited, board);
        func(row, col-1, chosen+1, word, visited, board);
        visited[row][col] = false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        rowsize = board.size();
        colsize = board[rowsize-1].size();
        vector<vector<bool>> visited(rowsize, vector<bool>(colsize));

        for (int i=0; i<rowsize; i++) {
            for (int j=0; j<colsize; j++) {
                if (board[i][j]==word[0]) {
                    func(i, j, 0, word, visited, board);
                    if (check) return true;
                }
            }
        }
        return false;
    }
};

