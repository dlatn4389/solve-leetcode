#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        int sSize = s.size();
        for (int i=0; i<sSize; i++) {
            if (s[i]!=t[i]) {
                return t[i];
            }
        }
        return t[sSize];
    }
};

int main() {
    cout << "Input string s below" << endl;
    string s; cin >> s;
    cout << "Input string t below" << endl;
    string t; cin >> t;

    cout << endl;
    cout << "****************print**************" << endl;
    Solution sol;
    cout << sol.findTheDifference(s, t);
}
