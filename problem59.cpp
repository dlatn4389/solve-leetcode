#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    bool isRange(int row, int col, int n) {
        if (row<0 or col<0 or row>=n or col>=n) return false;
        return true;
    }

    void rotate(int& heading) {
        heading++;
        if (heading>3) {
            heading -= 4;
        }
    }

    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n));
        vector<vector<bool>> visited(n, vector<bool>(n));

        vector<int> drow = {0, 1, 0, -1};
        vector<int> dcol = {1, 0, -1, 0};

        int heading = 0;
        int cnt = 0;

        int row = 0;
        int col = 0;

        while (cnt<n*n) {
            matrix[row][col] = cnt+1;
            visited[row][col] = true;
            cnt++;

            int nrow = row+drow[heading];
            int ncol = col+dcol[heading];
            if (isRange(nrow, ncol, n) and !visited[nrow][ncol]) {
                row = nrow;
                col = ncol;
            }
            else {
                rotate(heading);
                row = row+drow[heading];
                col = col+dcol[heading];
            }
        }

        return matrix;
    }
};

int main() {
    cout << "Input Number n below" << endl;
    int n; cin >> n;

    cout << endl;
    cout << "****************print****************" << endl;
    Solution sol;
    vector<vector<int>> matrix = sol.generateMatrix(n);

    for (auto i: matrix) {
        for (auto j: i) {
            cout << j << ' ';
        }
        cout << endl;
    }
}
