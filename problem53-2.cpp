#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxValue = -1234567890;
        int psum = 0;
        for (int i=0; i<nums.size(); i++) {
            psum = max(psum, 0)+nums[i];
            maxValue = max(psum, maxValue);
        }
        return maxValue;
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
    cout << "*****************print*******************" << endl;
    Solution sol;
    cout << sol.maxSubArray(nums);
}