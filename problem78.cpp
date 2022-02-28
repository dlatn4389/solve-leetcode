#include <iostream>
#include <algorithm>
using namespace std;
#include <vector>

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

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> v;
        for (int size=0; size<=nums.size(); size++) {
            combination(0, size, v, nums);
        }
        return ans;
    }
};
