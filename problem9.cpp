#include <iostream>
#include <algorithm>
using namespace std;
#include <stack>

class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0) {
            return false;
        }

        int temp_x = x;
        stack<int> st;

        while (temp_x!=0) {
            st.push(temp_x%10);
            temp_x /= 10;
        }

        while (!st.empty() and x%10==st.top()) {
            st.pop();
            x /= 10;
        }

        if (st.empty()) return true;
        return false;
    }
};