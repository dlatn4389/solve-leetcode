#include <iostream>
#include <algorithm>
using namespace std;
#include <vector>


class Solution {
private:
    vector<pair<char, int>> v = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
                                 {'C', 100}, {'D', 500}, {'M', 1000}};
    int find_int(char roman) {
        for (int i=0; i<v.size(); i++) {
            if (v[i].first==roman) {
                return v[i].second;
            }
        }
        return 0;
    }
public:
    int romanToInt(string s) {
        int answer = 0;

        for (int i=0; i<s.length(); i++) {
            char c = s[i];

            if (i==0) {
                answer += find_int(c);
                continue;
            }

            if (c=='V') {
                if (s[i-1]=='I') {
                    answer -= find_int(s[i-1]);
                    answer += 4;
                }
                else {
                    answer += find_int(c);
                }
            }
            else if (c=='X') {
                if (s[i-1]=='I') {
                    answer -= find_int(s[i-1]);
                    answer += 9;
                }
                else {
                    answer += find_int(c);
                }
            }
            else if (c=='L') {
                if (s[i-1]=='X') {
                    answer -= find_int(s[i-1]);
                    answer += 40;
                }
                else {
                    answer += find_int(c);
                }
            }
            else if (c=='C') {
                if (s[i-1]=='X') {
                    answer -= find_int(s[i-1]);
                    answer += 90;
                }
                else {
                    answer += find_int(c);
                }
            }
            else if (c=='D') {
                if (s[i-1]=='C') {
                    answer -= find_int(s[i-1]);
                    answer += 400;
                }
                else {
                    answer += find_int(c);
                }
            }
            else if (c=='M') {
                if (s[i-1]=='C') {
                    answer -= find_int(s[i-1]);
                    answer += 900;
                }
                else {
                    answer += find_int(c);
                }
            }
            else {
                answer += find_int(c);
            }
        }

        return answer;
    }
};

int main() {
    string s; cin >> s;
    Solution sol;

    cout << sol.romanToInt(s);
}
