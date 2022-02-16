#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> answer;
        answer.push_back(intervals[0]);
        int size = 1;

        for (int i=1; i<intervals.size(); i++) {
            int start_time = intervals[i][0];
            int end_time = intervals[i][1];
            if (start_time<=answer[size-1][1]) {
                answer[size-1][1] = max(answer[size-1][1], end_time);
            }
            else {
                answer.push_back({start_time, end_time});
                size++;
            }
        }
        return answer;
    }
};

int main() {
    cout << "Input Size of Vector below" << endl;
    int n; cin >> n;

    vector<vector<int>> v(n);
    cout << "Input Two elements of vector below" << endl;
    for (int i=0; i<n; i++) {
        int start, end; cin >> start >> end;
        v[i] = {start, end};
    }

    cout << endl;
    cout << "*************print****************" << endl;
    Solution sol;
    vector<vector<int>> answer = sol.merge(v);

    for (auto i: answer) {
        for (auto j: i) {
            cout << j << ' ';
        }
        cout << endl;
    }
}