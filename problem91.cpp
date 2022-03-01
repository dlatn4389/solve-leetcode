#include <iostream>
#include <algorithm>
using namespace std;
#include <vector>

class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.length()+1);
        dp[0] = 1;
        if (s[0]!='0') dp[1] = 1;

        for (int i=1; i<s.length(); i++) {
            if (s[i]!='0') {
                dp[i+1] += dp[i];
            }
            if (s[i-1]=='1' or (s[i-1]=='2' and s[i]<'7')) {
                dp[i+1] += dp[i-1];
            }
        }
        return dp[s.length()];
    }
};

int main() {
    cout << "Input String s below" << endl;
    string s; cin >> s;

    cout << endl;
    cout << "**************************print*********************" << endl;
    Solution sol;
    cout << sol.numDecodings(s);
}
