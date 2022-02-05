#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int answer = 0;
        auto unique_it = unique(nums.begin(), nums.end());
        auto it = nums.begin();
        while (it!=unique_it) {
            answer++;
            it++;
        }
        return answer;
    }
};

int main() {
    cout << "Input Number of Element below" << endl;
    int n; cin >> n;
    cout << "Input Element below" << endl;
    vector<int> nums;
    for (int i=0; i<n; i++) {
        int in; cin >> in;
        nums.push_back(in);
    }
    cout << endl;
    cout << "**************print******************" << endl;
    Solution sol;
    cout << sol.removeDuplicates(nums);
}