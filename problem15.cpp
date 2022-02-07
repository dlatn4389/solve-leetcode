#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> answer_set;
        for (int i=0; i<nums.size(); i++) {
            if (i>0 and nums[i]==nums[i-1]) continue;
            int left = i+1;
            int right = nums.size()-1;
            int sum = -nums[i];
            while (left<right) {
                if (nums[left]+nums[right]<sum) {
                    left++;
                }
                else if (nums[left]+nums[right]>sum) {
                    right--;
                }
                else {
                    answer_set.insert({nums[i], nums[left++], nums[right--]});
                }
            }
        }
        vector<vector<int>> answer(answer_set.begin(), answer_set.end());
        return answer;
    }
};

void print(const vector<vector<int>> &v) {
    for (int i=0; i<v.size(); i++) {
        for (int j=0; j<v[i].size(); j++) {
            cout << v[i][j] << ' ';
        }
        cout << endl;
    }
}

int main() {
    cout << "Input Number of Elements below" << endl;
    int n; cin >> n;

    cout << "Input Elements below" << endl;
    vector<int> nums(n);
    for (int i=0; i<n; i++) {
        cin >> nums[i];
    }

    cout << endl;
    cout << "************print***************" << endl;
    Solution sol;
    print(sol.threeSum(nums));
}
