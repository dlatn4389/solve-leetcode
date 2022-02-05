#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        auto it = find(nums.begin(), nums.end(), val);
        while (it!=nums.end()) {
            nums.erase(it);
            it = find(nums.begin(), nums.end(), val);
        }
        return nums.size();
    }
};

void print(const vector<int> &v) {
    for (int i=0; i<v.size(); i++) {
        cout << v[i] << ' ';
    }
}

int main() {
    cout << "Input Number of Element below" << endl;
    int n; cin >> n;
    cout << "Input Element below" << endl;
    vector<int> nums;
    for (int i=0; i<n; i++) {
        int in; cin >> in;
        nums.push_back(in);
    }
    cout << "Input val below" << endl;
    int val; cin >> val;

    cout << endl;
    cout << "***************print***********************" << endl;
    Solution sol;
    cout << sol.removeElement(nums, val) << endl;
    print(nums);
}