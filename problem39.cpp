#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
private:
    void backtracking(vector<int>& candidates, int target, int start, vector<int>& temp, vector<vector<int>>& answer) {
        if (target==0) {
            answer.push_back(temp);
        }
        for (int i=start; i<candidates.size(); i++) {
            int value = candidates[i];
            if (value<=target) {
                temp.push_back(value);
                backtracking(candidates, target-value, i, temp, answer);
                temp.pop_back();
            }
            else break;
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        vector<vector<int>> answer;
        backtracking(candidates, target, 0, temp, answer);
        return answer;
    }
};

void print(const vector<vector<int>>& v) {
    for (int i=0; i<v.size(); i++) {
        for (int j=0; j<v[i].size(); j++) {
            cout << v[i][j] << ' ';
        }
        cout << endl;
    }
}

int main () {
    cout << "Input Size of vector below" << endl;
    int n; cin >> n;

    cout << "Input Elements of vector below" << endl;
    vector<int> candidates(n);
    for (int i=0; i<n; i++) {
        cin >> candidates[i];
    }

    cout << "Input Target Number below" << endl;
    int target; cin >> target;

    cout << endl;
    cout << "******************print********************" << endl;
    Solution sol;
    print(sol.combinationSum(candidates, target));
}
