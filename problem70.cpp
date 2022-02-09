#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n==1) return 1;

        int dp[n+1];
        dp[1] = 1;
        dp[2] = 2;

        for (int i=3; i<=n; i++) {
            dp[i] = dp[i-2]+dp[i-1];
        }
        return dp[n];
    }
};

int main() {
    cout << "Input Number of Stairs below" << endl;
    int n; cin >> n;

    cout << endl;
    cout << "**************print**************" << endl;
    Solution sol;
    cout << sol.climbStairs(n);
}