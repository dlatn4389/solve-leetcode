#include <iostream>
#include <algorithm>
using namespace std;
#include <stack>
#include <vector>

class Solution {
public:
    vector<string> split(string s, char regex) {
        vector<string> v;

        string split_str = "";
        for (char c: s) {
            if (c==regex) {
                if (!split_str.empty()) {
                    v.push_back(split_str);
                    split_str = "";
                }
            }
            else {
                split_str += c;
            }
        }
        if (!split_str.empty()) {
            v.push_back(split_str);
        }

        return v;
    }

    stack<string> reverse_stack(stack<string>& st) {
        stack<string> ans;
        while (!st.empty()) {
            ans.push(st.top());
            st.pop();
        }
        return ans;
    }

    string simplifyPath(string path) {
        vector<string> splited_by_slash = split(path, '/');
        stack<string> st;
        for (string splited_path: splited_by_slash) {
            if (splited_path=="..") {
                if (st.empty()) {
                    continue;
                }
                else {
                    st.pop();
                }
            }
            else if (splited_path==".") continue;
            else st.push(splited_path);
        }

        string ans = "";
        st = reverse_stack(st);

        while (!st.empty()) {
            ans += '/';
            ans += st.top();
            st.pop();
        }

        if (ans.empty()) ans+='/';

        return ans;
    }
};

int main() {
    cout << "Input String path below" << endl;
    string path; cin >> path;

    cout << endl;
    cout << "********************print********************" << endl;
    Solution sol;
    cout << sol.simplifyPath(path);
}
