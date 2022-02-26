#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int arr[200][200];

    int comb(int n, int k) {
        int &ret = arr[n][k];
        if (ret!=0) return ret;

        if (k==0 or k==n) return ret=1;
        if (k==1 or k==n-1) return ret=n;
        return ret=comb(n-1, k-1)+comb(n-1, k);
    }

    int uniquePaths(int m, int n) {
        return comb(m+n-2, m-1);
    }
};

int main() {
    cout << "Input int m below" << endl;
    int m; cin >> m;
    cout << "Input int n below" << endl;
    int n; cin >> n;

    cout << endl;
    cout << "******************print*****************" << endl;
    Solution sol;
    cout << sol.uniquePaths(m, n);
}
