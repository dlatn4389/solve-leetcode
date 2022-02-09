#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    string coundAndSay(int n) {
        string answer = "1";
        for (int i=0; i<n-1; i++) {
            char prev = answer[0];
            int cnt = 1;
            string temp = "";
            for (int i=1; i<answer.length(); i++) {
                if (answer[i]==prev) {
                    cnt++;
                }
                else {
                    temp.push_back(cnt+'0');
                    temp.push_back(prev);
                    prev = answer[i];
                    cnt = 1;
                }
            }
            temp.push_back(cnt+'0');
            temp.push_back(prev);
            answer = temp;
        }
        return answer;
    }
};

int main() {
    cout << "Input Number below" << endl;
    int n; cin >> n;

    cout << endl;
    cout << "**************print***************" << endl;
    Solution sol;
    cout << sol.coundAndSay(n);
}

