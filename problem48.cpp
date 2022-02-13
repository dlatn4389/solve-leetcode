#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int size = matrix.size();
        int start = 0;

        while (size>1) {
            for (int i=0; i<size-1; i++) {
                int value = matrix[start][start];
                for (int row=start; row<start+size-1; row++) {
                    matrix[row][start] = matrix[row+1][start];
                }
                for (int col=start; col<start+size-1; col++) {
                    matrix[start+size-1][col] = matrix[start+size-1][col+1];
                }
                for (int row=start+size-1; row>start; row--) {
                    matrix[row][start+size-1] = matrix[row-1][start+size-1];
                }
                for (int col=start+size-1; col>start; col--) {
                    matrix[start][col] = matrix[start][col-1];
                }
                matrix[start][start+1] = value;
            }
            start++;
            size -= 2;
        }
    }
};

int main() {
    cout << "Input Size of 2D Array" << endl;
    int n; cin >> n;

    vector<vector<int>> matrix(n);
    for (int i=0; i<n; i++) {
        matrix[i].resize(n);
    }

    for (int i=0; i<n; i++) {
        cout << "Input Elements of " << i << "th row below" << endl;
        for (int j=0; j<n; j++) {
            cin >> matrix[i][j];
        }
    }

    cout << endl;
    cout << "*****************print*******************8" << endl;
    Solution sol;
    sol.rotate(matrix);
    for (auto i: matrix) {
        for (auto j: i) {
            cout << j << ' ';
        }
        cout << endl;
    }
}