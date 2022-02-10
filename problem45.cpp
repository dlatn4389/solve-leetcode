#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        ios::sync_with_stdio(0);
        cin.tie(NULL);
        cout.tie(NULL);

        int size = nums.size();
        vector<int> dp(size, 987654321);

        dp[0] = 0;
        for (int i=0; i<size; i++) {
            for (int j=i+1; j<size and j<=i+nums[i]; j++) {
                dp[j] = min(dp[j], dp[i]+1);
            }
        }
        return dp[size-1];
    }
};

int main() {
    cout << "Input Number of Elements below" << endl;
    int n; cin >> n;

    cout << "Input Elements below" << endl;
    vector<int> nums(n);
    for (int i=0; i<n; i++) {
        cin >> nums[i];
    }

    cout << endl;
    cout << "***************print*******************" << endl;
    Solution sol;
    cout << sol.jump(nums);
}
