#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<bool> visited;

    bool canJump(vector<int>& nums) {
        int size = nums.size();
        visited.resize(size);
        visited[0] = true;
        for (int i=0; i<size-1; i++) {
            if (visited[i]) {
                for (int j=i+1; j<size and j<=i+nums[i]; j++) {
                    visited[j] = true;
                }
            }
            if (visited[size-1]) return true;
        }
        return visited[size-1];
    }
};
