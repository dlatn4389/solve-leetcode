#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    unordered_map<int, int> cnts;
    vector<vector<int>> answer;

    void permutation(int chosen, vector<int>& nums, vector<int>& v) {
        if (chosen==0) {
            answer.push_back(v);
            return;
        }
        for (int i=-10; i<=10; i++) {
            if (cnts[i]>0) {
                cnts[i]--;
                v.push_back(i);
                permutation(chosen-1, nums, v);
                cnts[i]++;
                v.pop_back();
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        for (int i: nums) {
            cnts[i]++;
        }
        vector<int> v;
        permutation(nums.size(), nums, v);
        return answer;
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
    cout << "Input Size of Vector below" << endl;
    int n; cin >> n;

    cout << "Input Element of vector below" << endl;
    vector<int> nums(n);
    for (int i=0; i<n; i++) {
        cin >> nums[i];
    }

    cout << endl;
    cout << "***********************print**********************" << endl;
    Solution sol;
    print(sol.permuteUnique(nums));
}
