#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isLeaf(TreeNode* node) {
        if (!node->left and !node->right) return true;
        return false;
    }
    int func(TreeNode* node) {
        if (isLeaf(node)) return 0;

    }
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        if (isLeaf(root)) return 1;

        int l = 987654321, r = 987654321;
        if (root->left) {
            l = minDepth(root->left);
        }
        if (root->right) {
            r = minDepth(root->right);
        }
        return min(l, r)+1;
    }
};

int main() {
    TreeNode* root = new TreeNode(2);
    TreeNode* curr = root;
    for (int i=0; i<4; i++) {
        curr->right = new TreeNode(i+3);
        curr = curr->right;
    }

    Solution sol;
    cout << sol.minDepth(root);
}
