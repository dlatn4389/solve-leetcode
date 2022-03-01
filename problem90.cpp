#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#include <unordered_map>

class Solution {
public:
    vector<vector<int>> subsets;

    void func(int start, int chosen, vector<int>& v, vector<int>& keys, unordered_map<int, int>& radix) {
        if (chosen==0) {
            subsets.push_back(v);
            return;
        }
        for (int i=start; i<keys.size(); i++) {
            if (radix[keys[i]]>0) {
                radix[keys[i]]--;
                v.push_back(keys[i]);
                func(i, chosen-1, v, keys, radix);
                radix[keys[i]]++;
                v.pop_back();
            }
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> keys;
        unordered_map<int, int> radix;

        for (int i: nums) {
            radix[i]++;
            if (keys.empty() or keys[keys.size()-1]!=i) {
                keys.push_back(i);
            }
        }
        for (int i=0; i<=nums.size(); i++) {
            vector<int> v;
            func(0, i, v, keys, radix);
        }
        return subsets;
    }
};

int main() {
    cout << "Input size of vector below" << endl;
    int n; cin >> n;

    cout << "Input Elements of vector below" << endl;
    vector<int> nums(n);
    for (int i=0; i<n; i++) {
        cin >> nums[i];
    }

    cout << endl;
    cout << "**********************print*******************" << endl;
    Solution sol;
    vector<vector<int>> subsets = sol.subsetsWithDup(nums);

    for (auto i: subsets) {
        for (auto j: i) {
            cout << j << ' ';
        }
        cout << endl;
    }
}