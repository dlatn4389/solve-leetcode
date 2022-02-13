#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        set<string> keys;
        unordered_map<string, vector<string>> um;

        for (string str: strs) {
            string temp = str;
            sort(temp.begin(), temp.end());
            keys.insert(temp);
            um[temp].push_back(str);
        }

        vector<vector<string>> ans;
        for (auto iter=keys.begin(); iter!=keys.end(); iter++) {
            ans.push_back(um[*iter]);
        }
        return ans;
    }
};

void print(const vector<vector<string>>& v) {
    for (auto i: v) {
        for (auto j: i) {
            cout << j << ' ';
        }
        cout << endl;
    }
}

int main() {
    cout << "Input Size of Vector below" << endl;
    int n; cin >> n;

    vector<string> strs(n);
    cout << "Input Elements below" << endl;
    for (int i=0; i<n; i++) {
        cin >> strs[i];
    }

    cout << endl;
    cout << "***************print**************" << endl;
    Solution sol;
    print(sol.groupAnagrams(strs));
}
