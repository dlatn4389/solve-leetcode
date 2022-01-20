#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
private:
    const int limit = 2147483647;

    bool isdigit(char c) {
        if (c>='0' and c<='9') {
            return true;
        }
        return false;
    }

    bool isobstacle(char c) {
        if (c>='a' and c<='z') {
            return true;
        }
        if (c>='A' and c<='Z') {
            return true;
        }
        if (c=='.') return true;
        return false;
    }

public:
    int myAtoi(string s) {
        int digit_start_idx = 0;
        bool positive = false;
        bool negative = false;

        while (digit_start_idx<s.length() and !isdigit(s[digit_start_idx])) {
            if (isobstacle(s[digit_start_idx])) {
                return 0;
            }
            if ((positive or negative) and s[digit_start_idx]==' ') {
                return 0;
            }
            if (s[digit_start_idx]=='+') {
                if (positive) return 0;
                positive = true;
            }
            if (s[digit_start_idx]=='-') {
                if (negative) return 0;
                negative = true;
            }
            digit_start_idx++;
        }

        if (positive and negative) return 0;

        if (digit_start_idx==s.length()) {
            return 0;
        }

        int answer = 0;
        while (isdigit(s[digit_start_idx])) {
            if (answer>limit/10) {
                if (negative) {
                    return -limit-1;
                }
                return limit;
            }
            answer *= 10;

            if (answer==limit-7) {
                if (negative and s[digit_start_idx]-'0'>=8) {
                    return -limit-1;
                }
                else if (s[digit_start_idx]-'0'>=8) {
                    return limit;
                }
            }
            answer += s[digit_start_idx]-'0';

            digit_start_idx++;
        }

        if (negative) answer = -answer;
        return answer;
    }
};