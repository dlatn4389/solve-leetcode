#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int cnt = 0;
        for (int i=s.length()-1; i>=0; i--) {
            if (s[i]==' ' and cnt==0) continue;
            else if (s[i]==' ' and cnt>0) break;
            else cnt++;
        }
        return cnt;
    }
};

int main() {
    cout << "Input string s below" << endl;
    string s; getline(cin, s);

    cout << endl;
    cout << "*******************print***********************" << endl;
    Solution sol;
    cout << sol.lengthOfLastWord(s);
}
