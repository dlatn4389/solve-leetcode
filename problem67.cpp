#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        if (b.length()>a.length()) {
                swap(a, b);
        }
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        string answer = "";
        bool carry = false;

        for (int i=0; i<b.length(); i++) {
            int value = (a[i]-'0')+(b[i]-'0')+carry;
            carry = false;

            if (value>=2) {
                carry = true;
                value -= 2;
            }
            answer.push_back(value+'0');
        }

        for (int i=b.length(); i<a.length(); i++) {
            int value = a[i]-'0'+carry;
            carry = false;

            if (value>=2) {
                carry = true;
                value -= 2;
            }
            answer.push_back(value+'0');
        }

        if (carry) {
            answer.push_back('1');
        }

        reverse(answer.begin(), answer.end());
        return answer;
    }
};

int main() {
    cout << "Input Binary1 below" << endl;
    string a; cin >> a;

    cout << "Input Binary2 below" << endl;
    string b; cin >> b;

    cout << endl;
    cout << "**************print**************8" << endl;
    Solution sol;
    cout << sol.addBinary(a, b);
}