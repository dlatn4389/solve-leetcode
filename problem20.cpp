#include <iostream>
#include <algorithm>
using namespace std;
#include <stack>

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char c: s) {
            if (c=='(' or c=='[' or c=='{') {
                st.push(c);
            }
            else {
                if (c==')') {
                    if (st.empty() or st.top()!='(') return false;
                    st.pop();
                }
                else if (c==']') {
                    if (st.empty() or st.top()!='[') return false;
                    st.pop();
                }
                else if (c=='}') {
                    if (st.empty() or st.top()!='{') return false;
                    st.pop();
                }
            }
        }
        if (!st.empty()) return false;
        return true;
    }
};

int main() {
    cout << "Input String below" << endl;
    string s; cin >> s;

    cout << endl;
    cout << "*******************print**********************" << endl;
    Solution sol;
    cout << sol.isValid(s);
}
