#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;

    void combination(int start, int k, vector<int>& v, vector<int>& nums) {
        if (k==0) {
            ans.push_back(v);
            return;
        }

        for (int i=start; i<nums.size(); i++) {
            v.push_back(nums[i]);
            combination(i+1, k-1, v, nums);
            v.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
       vector<int> nums(n);
       for (int i=0; i<n; i++) {
           nums[i] = i+1;
       }
       vector<int> v;
       combination(0, k, v, nums);
       return ans;
    }
};
