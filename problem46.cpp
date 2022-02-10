#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> perm;
    vector<bool> visited;

    void permutation(int chosen, vector<int>& nums, vector<int>& v) {
        if (chosen==0) {
            perm.push_back(v);
            return;
        }
        for (int i=0; i<nums.size(); i++) {
            if (!visited[i]) {
                visited[i] = true;
                v.push_back(nums[i]);
                permutation(chosen-1, nums, v);
                visited[i] = false;
                v.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        visited.resize(nums.size());
        vector<int> v;
        permutation(nums.size(), nums, v);
        return perm;
    }
};

void print(const vector<vector<int>>& v) {
    for (int i=0; i<v.size(); i++) {
        for (int j=0; j<v[i].size();j++) {
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
    cout << "****************Print****************" << endl;
    Solution sol;
    print(sol.permute(nums));
}