#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int func(int m, int n, vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp) {
        if (m<0 or n<0) return 0;
        int& ret = dp[m][n];
        if (obstacleGrid[m][n]==1) return 0;
        if (ret!=-1) return ret;

        return ret=func(m, n-1, obstacleGrid, dp)+func(m-1, n, obstacleGrid, dp);
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        dp[0][0] = 1;
        return func(m-1, n-1, obstacleGrid, dp);
    }
};

int main() {
    cout << "Input Number of Rows below" << endl;
    int n; cin >> n;

    cout << "Input Number of Columns below" << endl;
    int m; cin >> m;

    vector<vector<int>> obstacleGrid(n, vector<int>(m));

    for (int i=0; i<n; i++) {
        cout << "Input Elements of " << i << "th row below" << endl;
        for (int j=0; j<m; j++) {
            cin >> obstacleGrid[i][j];
        }
    }

    cout << endl;
    cout << "**************print*****************" << endl;
    Solution sol;
    cout << sol.uniquePathsWithObstacles(obstacleGrid);
}