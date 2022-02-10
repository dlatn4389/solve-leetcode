#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

class Solution {
private:
    set<vector<int>> answer_set;
    void backtracking(int start, vector<int>& temp, vector<int>& candidates, int target) {
        if (target==0) {
            answer_set.insert(temp);
            return;
        }
        for (int i=start; i<candidates.size(); i++) {
            if (i>start and candidates[i]==candidates[i-1]) continue;
            if (candidates[i]>target) break;
            else {
                temp.push_back(candidates[i]);
                backtracking(i+1, temp, candidates, target-candidates[i]);
                temp.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        backtracking(0, temp, candidates, target);
        vector<vector<int>> answer(answer_set.begin(), answer_set.end());

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

int main() {
    cout << "Input Number of Elements below" << endl;
    int n; cin >> n;

    cout << "Input Elements below" << endl;
    vector<int> candidates(n);
    for (int i=0; i<n; i++) {
        cin >> candidates[i];
    }

    cout << "Input Target Number below" << endl;
    int target; cin >> target;

    cout << endl;
    cout << "****************print*********************" << endl;
    Solution sol;
    print(sol.combinationSum2(candidates, target));
}