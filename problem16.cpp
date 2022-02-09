#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int numSize = nums.size();
        int closestSum = nums[0]+nums[1]+nums[2];
        for (int i=0; i<numSize; i++) {
            if (i>0 and nums[i]==nums[i-1]) continue;
            int lo = i+1;
            int hi = numSize-1;

            while (lo<hi) {
                int sum = nums[i]+nums[lo]+nums[hi];
                if (abs(target-sum)<abs(target-closestSum)) {
                    closestSum = sum;
                }
                if (sum<target) {
                    lo++;
                }
                else if (sum>target) {
                    hi--;
                }
                else {
                    return sum;
                }
            }
        }
        return closestSum;
    }
};

int main() {
    cout << "Input Size of vector below" << endl;
    int n; cin >> n;

    cout << "Input Elements of vector below" << endl;
    vector<int> nums(n);
    for (int i=0; i<n; i++) {
        cin >> nums[i];
    }

    cout << "Input Target Number below" << endl;
    int target; cin >> target;

    cout << endl;
    cout << "******************print********************" << endl;
    Solution sol;
    cout << sol.threeSumClosest(nums, target);
}
