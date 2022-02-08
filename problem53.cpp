#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
private:
    int func(int start, int end, vector<int>& nums) {
        int numSize = nums.size();
        //cout << "start: " << start << ", end: " << end << endl;
        if (start==end) return nums[start];

        int mid = (start+end)/2;
        int answer = max(func(start, mid, nums), func(mid+1, end, nums));
        int maxLeftSum = -1234567890, maxRightSum = -1234567890;
        int sum = 0;

        for (int i=mid; i>=start; i--) {
            sum += nums[i];
            maxLeftSum = max(maxLeftSum, sum);
        }
        sum = 0;
        for (int i=mid+1; i<=end; i++) {
            sum += nums[i];
            maxRightSum = max(maxRightSum, sum);
        }
        answer = max(answer, maxLeftSum+maxRightSum);
        return answer;
    }

public:
    int maxSubArray(vector<int>& nums) {
        return func(0, nums.size()-1, nums);
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