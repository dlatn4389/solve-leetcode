#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int size = matrix.size();
        for (int i=0; i<size/2; i++) {
            for (int j=0; j<size; j++) {
                swap(matrix[size-1-i][j], matrix[i][j]);
            }
        }
        for (int i=0; i<size; i++) {
            for (int j=i+1; j<size; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
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