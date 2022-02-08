#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool carry = true;
        vector<int> answer(digits.rbegin(), digits.rend());

        for (int i=0; i<answer.size(); i++) {
            if (carry) {
                answer[i]++;
                carry = false;
            }
            if (answer[i]>=10) {
                answer[i] -= 10;
                carry = true;
            }
        }
        if (carry) {
            answer.push_back(1);
        }
        reverse(answer.begin(), answer.end());
        return answer;
    }
};

void print(const vector<int>& v) {
    for (int i=0; i<v.size(); i++) {
        cout << v[i] << ' ';
    }
}

int main() {
    cout << "Input Size of vector below" << endl;
    int n; cin >> n;

    cout << "Input Elements of vector below" << endl;
    vector<int> digits(n);
    for (int i=0; i<n; i++) {
        cin >> digits[i];
    }

    cout << endl;
    cout << "*****************print*******************" << endl;
    Solution sol;
    print(sol.plusOne(digits));
}
