#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1=="0" or num2=="0") return "0";

        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        int num1_length = num1.length();
        int num2_length = num2.length();
        vector<int> answer(num1_length+num2_length);

        for (int i=0; i<num1_length; i++) {
            for (int j=0; j<num2_length; j++) {
                answer[i+j] += (num1[i]-'0')*(num2[j]-'0');
            }
        }

        for (int i=0; i<num1_length+num2_length-1; i++) {
            answer[i+1] += answer[i]/10;
            answer[i] %= 10;
        }

        string ans = "";
        for (int i=0; i<num1_length+num2_length-1; i++) {
            ans.push_back(answer[i]+'0');
        }
        if (answer[num1_length+num2_length-1]!=0) {
            ans.push_back(answer[num1_length+num2_length-1]+'0');
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    cout << "Input First Number below" << endl;
    string num1; cin >> num1;

    cout << "Input Second Number below" << endl;
    string num2; cin >> num2;

    cout << endl;
    cout << "***********print*************" << endl;
    Solution sol;
    cout << sol.multiply(num1, num2);
}
