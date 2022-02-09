#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
private:
    bool rowTest(vector<vector<char>> board) {
        for (int row=0; row<9; row++) {
            string visited = "000000000";
            for (int col=0; col<9; col++) {
                char c = board[row][col];
                if (c!='.') {
                    if (visited[c-'1']=='1') {
                        return false;
                    }
                    visited[c-'1'] = '1';
                }
            }
        }
        return true;
    }
    bool colTest(vector<vector<char>> board) {
        for (int col=0; col<9; col++) {
            string visited = "000000000";
            for (int row=0; row<9; row++) {
                char c = board[row][col];
                if (c!='.') {
                    if (visited[c-'1']=='1') {
                        return false;
                    }
                    visited[c-'1'] = '1';
                }
            }
        }
        return true;
    }
    bool boxText(vector<vector<char>> board) {
        vector<int> nums = {0,3,6};
        for (int row: nums) {
            for (int col: nums) {
                string visited = "000000000";
                for (int i=row; i<row+3; i++) {
                    for (int j=col; j<col+3; j++) {
                        char c = board[i][j];
                        if (c!='.') {
                            if (visited[c-'1']=='1') {
                                return false;
                            }
                            visited[c-'1'] = '1';
                        }
                    }
                }
            }
        }
        return true;
    }
public:
    bool isVaildSudoku(vector<vector<char>>& board) {
        return rowTest(board) and colTest(board) and boxText(board);
    }
};

int main() {

}
