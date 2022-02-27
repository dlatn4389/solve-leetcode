#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Position {
    int row;
    int col;
    Position(int row, int col): row(row), col(col) {}
};

class Solution {
public:
    vector<Position> get_position_of_zero(vector<vector<int>>& matrix) {
        vector<Position> ans;
        for (int i=0; i<matrix.size(); i++) {
            for (int j=0; j<matrix[i].size(); j++) {
                if (matrix[i][j]==0) {
                    ans.push_back(Position(i, j));
                }
            }
        }
        return ans;
    }

    void changeElements_toZero(Position pos, vector<vector<int>>& matrix) {
        int row = pos.row;
        int col = pos.col;

        for (int &i: matrix[row]) {
            i = 0;
        }
        for (int i=0; i<matrix.size(); i++) {
            matrix[i][col] = 0;
        }
    }

    void setZeroes(vector<vector<int>>& matrix) {
        vector<Position> positions = get_position_of_zero(matrix);
        for (Position pos: positions) {
            changeElements_toZero(pos, matrix);
        }
    }
};
