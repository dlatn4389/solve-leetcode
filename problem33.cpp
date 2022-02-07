#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
private:
    int binarySearch(int start, int end, vector<int>& nums, int target) {
        int size = nums.size();
        if (start<0 or end<0 or start>=size or end>=size) {
            return -1;
        }
        if (start>end) return -1;
        if (nums[start]<nums[end]) {
            if (target<nums[start]) return -1;
            if (target>nums[end]) return -1;
        }
        int mid = (start+end)/2;
        if (nums[mid]!=target) {
            return max(binarySearch(mid+1, end, nums, target), binarySearch(start, mid-1, nums, target));
        }

        return mid;
    }
public:
    int search(vector<int> &nums, int target) {
        return binarySearch(0, nums.size()-1, nums, target);
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

    cout << "Input target below" << endl;
    int target; cin >> target;

    cout << endl;
    cout << "*****************print*********************" << endl;
    Solution sol;
    cout << sol.search(nums, target);
}