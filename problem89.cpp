#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<string>> dp;

    int binToDec(string binary) {
        int sum = 0;
        int rep = 1;

        for (int i=binary.length()-1; i>=0; i--) {
            sum += rep*(binary[i]-'0');
            rep *= 2;
        }
        return sum;
    }

    vector<int> grayCode(int n) {
        dp.resize(n+1);
        dp[1] = {"0", "1"};

        for (int i=2; i<=n; i++) {
            for (int j=0; j<dp[i-1].size(); j++) {
                if (j%2==0) {
                    dp[i].push_back(dp[i-1][j]+'0');
                    dp[i].push_back(dp[i-1][j]+'1');
                }
                else {
                    dp[i].push_back(dp[i-1][j]+'1');
                    dp[i].push_back(dp[i-1][j]+'0');
                }
            }
        }

        vector<int> answer;
        for (string s: dp[n]) {
            answer.push_back(binToDec(s));
        }
        return answer;
    }
};

int main() {
    cout << "Input Number n below" << endl;
    int n; cin >> n;

    cout << endl;
    cout << "********************print*****************" << endl;
    Solution sol;
    vector<int> answer = sol.grayCode(n);

    for (int i: answer) {
        cout << i << ' ';
    }
}
