#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int addDigits(int num) {
       while (num/10!=0) {
           int sum = 0;
           while (num!=0) {
               sum += num%10;
               num /= 10;
           }
           num = sum;
       }
       return num;
    }
};

int main() {
    cout << "Input Number below" << endl;
    int num; cin >> num;

    cout << endl;
    cout << "******************print****************" << endl;
    Solution sol;
    cout << sol.addDigits(num);
}
