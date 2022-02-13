#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<bool>> visited;
    int drow[4] = {0, 1, 0, -1};
    int dcol[4] = {1, 0, -1, 0};

    void turn(int& direction) {
        direction++;
        if (direction>3) {
            direction -= 4;
        }
    }

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        visited.resize(n);
        for (int i=0; i<n; i++) {
            visited[i].resize(m);
        }

        int direction = 0, cnt = 0;

        vector<int> answer(n*m);
        int row=0, col=0;
        while (cnt<n*m) {
            answer[cnt] = matrix[row][col];
            visited[row][col] = true;
            cnt++;

            int nrow = row+drow[direction];
            int ncol = col+dcol[direction];
            if (nrow<0 or nrow>=n or ncol<0 or ncol>=m or visited[nrow][ncol]) {
                turn(direction);
                nrow = row+drow[direction];
                ncol = col+dcol[direction];
            }
            row = nrow;
            col = ncol;
        }
        return answer;
    }
};

int main() {

}
