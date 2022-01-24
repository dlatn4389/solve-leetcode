#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
private:
    vector<string> intToStr = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void func(int idx, const string digits, string& str, vector<string>& answer) {
        if (idx==digits.size()) {
            answer.push_back(str);
            return;
        }
        string digit_strs = intToStr[digits[idx]-'0'];
        for (int i=0; i<digit_strs.length(); i++) {
            string temp = str+digit_strs[i];
            func(idx+1, digits, temp, answer);
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> answer;
        if (digits.length()==0) {
            return answer;
        }
        string str = "";
        func(0, digits, str, answer);
        return answer;
    }
};

void print(const vector<string> &v) {
    for (int i=0; i<v.size(); i++) {
        cout << v[i] << ' ';
    }
}

int main() {
    string digits; cin >> digits;
    Solution sol;
    print(sol.letterCombinations(digits));
}
