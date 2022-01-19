#include <iostream>
using namespace std;
#include <algorithm>
#include <queue>

class Solution {
public:
    int reverse(int x) {
        const int limit = 2147483647;

        if (x<=-limit) return 0;

        queue<int> q;
        bool negative = false;
        if (x<0) {
            negative = true;
            x = -x;
        }

        while (x!=0) {
            q.push(x%10);
            x /= 10;
        }

        int answer = 0;
        while (!q.empty()) {
            if (answer>limit/10)  {
                return 0;
            }
            answer *= 10;
            answer += q.front();
            q.pop();
        }

        if (negative) answer = -answer;

        return answer;
    }
};

int main() {
    int x; cin >> x;
    Solution sol;

    cout << sol.reverse(x);
}
