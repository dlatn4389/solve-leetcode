#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n));
        dp[0][0] = grid[0][0];
        for (int col=1; col<n; col++) {
            dp[0][col] = dp[0][col-1]+grid[0][col];
        }
        for (int row=1; row<m; row++) {
            dp[row][0] = dp[row-1][0]+grid[row][0];
        }

        for (int row=1; row<m; row++) {
            for (int col=1; col<n; col++) {
                dp[row][col] = min(dp[row-1][col], dp[row][col-1])+grid[row][col];
            }
        }

        return dp[m-1][n-1];
    }
};

int main() {
    cout << "Input Number of Rows below" << endl;
    int m; cin >> m;

    cout << "Input Number of Columns below" << endl;
    int n; cin >> n;

    vector<vector<int>> grid(m, vector<int>(n));

    for (int i=0; i<m; i++) {
        cout << "Input Elements of " << i << "th row below" << endl;
        for (int j=0; j<n; j++) {
            cin >> grid[i][j];
        }
    }

    cout << endl;
    cout << "*********************print********************" << endl;
    Solution sol;
    cout << sol.minPathSum(grid);
}
