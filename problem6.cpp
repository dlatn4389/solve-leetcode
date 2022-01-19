#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows==1) {
            return s;
        }
        int interval = numRows + (numRows-2);
        int length = s.length();

        string answer = "";
        int idx = 0;
        while (idx<length) {
            answer += s[idx];
            idx += interval;
        }

        for (int i=1; i<numRows-1; i++) {
            idx = 0;
            while (idx<length+interval) {
                if (idx-i>=0 and idx-i<length) {
                    answer += s[idx-i];
                }
                if (idx+i>=0 and idx+i<length) {
                    answer += s[idx+i];
                }
                idx += interval;
            }
        }

        idx = numRows-1;
        while (idx<length) {
            answer += s[idx];
            idx += interval;

        }
        return answer;
    }
};

int main() {
    string s;
    int numRows;
    cin >> s >> numRows;

    Solution sol;
    cout << sol.convert(s, numRows);
}