#include <iostream>
#include <algorithm>
using namespace std;
#include <vector>

class Solution {
    vector<pair<int, string>> v = {{1,"I"}, {2, "II"}, {3, "III"},
                                   {4, "IV"}, {5, "V"}, {6, "VI"}, {7, "VII"}, {8, "VIII"},
                                   {9, "IX"}, {10, "X"}, {20, "XX"}, {30, "XXX"}, {40, "XL"},
                                   {50, "L"}, {60, "LX"}, {70, "LXX"}, {80, "LXXX"}, {90, "XC"},
                                   {100, "C"}, {200, "CC"}, {300, "CCC"}, {400, "CD"}, {500,"D"},
                                   {600, "DC"}, {700, "DCC"}, {800, "DCCC"}, {900, "CM"}, {1000, "M"},
                                   {2000, "MM"}, {3000, "MMM"}};

    string findRoman(int n) {
        for (int i=0; i<v.size(); i++) {
            if (v[i].first==n) {
                return v[i].second;
            }
        }
        return "";
    }
public:
    string intToRoman(int num) {
        string answer = "";
        int mul = 1;

        while (num!=0) {
            int n = num%10;
            n *= mul;
            string roman = findRoman(n);
            reverse(roman.begin(), roman.end());
            answer += roman;

            num /= 10;
            mul *= 10;
        }
        reverse(answer.begin(), answer.end());
        return answer;
    }
};

int main() {
    int num; cin >> num;
    Solution sol;

    cout << sol.intToRoman(num);
}