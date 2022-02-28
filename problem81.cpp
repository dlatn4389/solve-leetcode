#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
private:
    bool binarySearch(int start, int end, vector<int>& nums, int target) {
        int size = nums.size();
        if (start<0 or end<0 or start>=size or end>=size) {
            return false;
        }
        if (start>end) return false;
        if (nums[start]<nums[end]) {
            if (target<nums[start]) return false;
            if (target>nums[end]) return false;
        }
        int mid = (start+end)/2;
        if (nums[mid]==target) return true;

        return binarySearch(mid+1, end, nums, target) or binarySearch(start, mid-1, nums, target);

    }
public:
    bool search(vector<int> &nums, int target) {
        return binarySearch(0, nums.size()-1, nums, target);
    }
};
