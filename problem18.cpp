#include <iostream>
#include <algorithm>
using namespace std;
#include <vector>

class Solution {
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> answer;
        for (int i=0; i<nums.size(); i++) {
            for (int j=i+1; j<nums.size(); j++) {
                int sum = target-nums[i]-nums[j];

                int left = j+1;
                int right = nums.size()-1;
                while (left<right) {
                    if (nums[left]+nums[right]<sum) {
                        left++;
                    }
                    else if (nums[left]+nums[right]>sum) {
                        right--;
                    }
                    else {
                        answer.push_back({nums[i], nums[j], nums[left++], nums[right--]});
                    }
                }
            }
        }
        sort(answer.begin(), answer.end());
        answer.erase(unique(answer.begin(), answer.end()), answer.end());
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
    vector<int> nums;
    // 원소의 개수
    cout << "Input number of element below" << endl;
    int n; cin >> n;
    cout << "Input elements below" << endl;
    while (n--) {
        int in; cin >> in;
        nums.push_back(in);
    }
    cout << "Input target number below" << endl;
    int target; cin >> target;

    cout << endl;
    Solution sol;
    cout << "********************print*********************" << endl;
    print(sol.fourSum(nums, target));
}