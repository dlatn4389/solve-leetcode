#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int numSize = nums.size();
        int lower_bound = -1, upper_bound = -1;

        int start = 0;
        int end = numSize-1;
        while (start<=end) {
            int mid = (start+end)/2;
            if (nums[mid]<=target) {
                if (nums[mid]==target) {
                    upper_bound = mid;
                }
                start = mid+1;
            }
            else {
                end = mid-1;
            }
        }

        start = 0;
        end = numSize-1;
        while (start<=end) {
            int mid = (start+end)/2;
            if (nums[mid]<target) {
                start = mid+1;
            }
            else {
                if (nums[mid]==target) {
                    lower_bound = mid;
                }
                end = mid-1;
            }
        }

        return {lower_bound, upper_bound};
    }
};

void print(const vector<int>& v) {
    for (int i=0; i<v.size(); i++) {
        cout << v[i] << ' ';
    }
}

int main() {
    cout << "Input Number of Elements below" << endl;
    int n; cin >> n;

    cout << "Input Elemets below" << endl;
    vector<int> nums(n);
    for (int i=0; i<n; i++) {
        cin >> nums[i];
    }

    cout << "Input Target Number below" << endl;
    int target; cin >> target;

    cout << endl;
    cout << "************print*************88" << endl;
    Solution sol;
    print(sol.searchRange(nums, target));
}
