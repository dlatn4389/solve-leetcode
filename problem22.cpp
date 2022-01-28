#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
private:
    void func(int left, int right, string str, vector<string>& answer) {
        if (left==0 and right==0) {
            answer.push_back(str);
            return;
        }
        if (left>right) return;
        if (left>0) {
            func(left-1, right, str+"(", answer);
        }
        if (right>0){
            func(left, right-1, str+")", answer);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> answer;
        func(n, n, "", answer);
        return answer;
    }
};

void print(const vector<string> &v) {
    for (int i=0; i<v.size(); i++) {
        cout << v[i] << ' ';
    }
}

int main() {
    cout << "Input int n below" << endl;
    int n; cin >> n;
    cout << endl;
    cout << "*******************print******************" << endl;
    Solution sol;
    print(sol.generateParenthesis(n));
}
