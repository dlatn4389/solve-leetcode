#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

class Solution {
public:
    int mySqrt(int x) {
        ll start = 0;
        ll end = 2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2;

        int answer;
        while (start<=end) {
            ll mid = (start+end)/2;
            if (mid*mid>x) {
                end = mid-1;
            }
            else {
                answer = mid;
                start = mid+1;
            }
        }
        return answer;
    }
};

int main() {
    cout << "Input Number below" << endl;
    int n; cin >> n;

    cout << endl;
    cout << "***********print***************" << endl;
    Solution sol;
    cout << sol.mySqrt(n);
}