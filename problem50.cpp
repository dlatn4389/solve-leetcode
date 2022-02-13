#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if (n==0) return (double)1;

        double half = myPow(x, n/2);
        if (n%2==1) {
            return half*half*x;
        }
        else if (n%2==-1) {
            return half*half*(1/x);
        }
        return half*half;
    }
};

int main() {
    cout << "Input Double below" << endl;
    double x; cin >> x;

    cout << "Input Number below" << endl;
    int n; cin >> n;

    Solution sol;
    cout << endl;
    cout << "***************print***************" << endl;
    cout << sol.myPow(x, n);
}
