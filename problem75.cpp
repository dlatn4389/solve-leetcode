#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> radix(3);

        for (int i: nums) {
            radix[i]++;
        }
        int idx = 0;

        for (int i=0; i<=2; i++) {
            while (radix[i]!=0) {
                nums[idx++] = i;
                radix[i]--;
            }
        }
    }
};

int main() {
    cout << "Input Number of Elements below" << endl;
    int n; cin >> n;

    cout << "Input Elements of vector below" << endl;
    vector<int> nums(n);
    for (int i=0; i<n; i++) {
        cin >> nums[i];
    }

    Solution sol;
    cout << endl;
    cout << "*****************print*************" << endl;
    sol.sortColors(nums);

    for (auto i: nums) {
        cout << i << ' ';
    }
}
