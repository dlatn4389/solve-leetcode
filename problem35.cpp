#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int> &nums, int target) {
        int start = 0;
        int end = nums.size()-1;

        while (start<=end) {
            int mid = (start+end)/2;
            if (nums[mid]>target) {
                end = mid-1;
            }
            else if (nums[mid]<target) {
                start = mid+1;
            }
            else {
                return mid;
            }
        }
        return start;
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

    cout << "Input Target below" << endl;
    int target; cin >> target;

    cout << endl;
    cout << "****************print***********************" << endl;
    Solution sol;
    cout << sol.searchInsert(nums, target);
}