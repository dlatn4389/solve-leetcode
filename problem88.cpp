#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int idx1 = m-1, idx2 = n-1, idx = m+n-1;
        while (idx1>=0 and idx2>=0) {
            if (nums1[idx1]>=nums2[idx2]) {
                nums1[idx--] = nums1[idx1--];
            }
            else {
                nums1[idx--] = nums2[idx2--];
            }
        }
        if (idx1<0) {
            while (idx >= 0) {
                nums1[idx--] = nums2[idx2--];
            }
        }
    }
};

void print(const vector<int>& v) {
    for (int i=0; i<v.size(); i++) {
        cout << v[i] << ' ';
    }
}

int main() {
    cout << "Input Size of vector1 below" << endl;
    int n1; cin >> n1;

    cout << "Input Elements of vector1 below" << endl;
    vector<int> nums1(n1);
    for (int i=0; i<n1; i++) {
        cin >> nums1[i];
    }

    cout << "Input Size of vector2 below" << endl;
    int n2; cin >> n2;

    cout << "Input Elements of vector2 below" << endl;
    vector<int> nums2(n2);
    for (int i=0; i<n2; i++) {
        cin >> nums2[i];
    }

    cout << endl;
    cout << "*************print***************" << endl;
    Solution sol;
    sol.merge(nums1, n1-n2, nums2, n2);
    print(nums1);
}