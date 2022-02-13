#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    bool edgecase1(vector<int>& nums, int k) {
        int maxVal = nums[0];
        int minVal = nums[0];
        for (int i=1; i<nums.size(); i++) {
            maxVal = max(maxVal, nums[i]);
            minVal = min(minVal, nums[i]);
        }
        if (k>=0 and maxVal<0) return true;
        if (k<=0 and minVal>0) return true;
        return false;
    }
public:
    int subarraySum(vector<int>& nums, int k) {

        int start = 0;
        int end = 0;
        int answer = 0;
        while (end<=nums.size()) {
            int sum = 0;
            for (int i=start; i<end; i++) {
                sum += nums[i];
            }
            if (sum>k) {
                start++;
            }
            else if (sum<k) {
                end++;
            }
            else {
                answer++;
                start++;
            }
        }
        return answer;
    }
};

int main() {
    cout << "Input Number of Elements below" << endl;
    int n; cin>>n;

    cout << "Input Elements below" << endl;
    vector<int> nums(n);
    for (int i=0; i<n; i++) {
        cin >> nums[i];
    }

    cout << "Input Target Number below" << endl;
    int k; cin >> k;

    cout << endl;
    cout << "**************print******************" << endl;
    Solution sol;
    cout << sol.subarraySum(nums, k);
}
