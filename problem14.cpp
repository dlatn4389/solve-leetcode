#include <iostream>
#include <algorithm>
using namespace std;
#include <vector>

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size()==0) return "";

        string str = strs[0];

        for (int i=1; i<strs.size(); i++) {
            while (strs[i].find(str)==string::npos) {
                str = str.substr(0, str.length()-1);
            }
        }
        return str;
    }
};

int main() {
    vector<string> strs;
    // strs의 원소의 개수
    int n; cin >> n;

    while (n--) {
        string str;
        cin >> str;
        strs.push_back(str);
    }

    Solution sol;
    cout << sol.longestCommonPrefix(strs);
}