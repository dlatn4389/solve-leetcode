#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans = "";
        while (columnNumber!=0) {
            columnNumber -= 1;
            ans += columnNumber%26+'A';
            columnNumber /= 26;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    cout << "Input Number below" << endl;
    int columnNumber; cin >> columnNumber;

    cout << endl;
    cout << "*************print****************" << endl;
    Solution sol;
    cout << sol.convertToTitle(columnNumber);
}
