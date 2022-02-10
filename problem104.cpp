#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int max_depth = 0;

    void traversal(TreeNode* node, int depth) {
        if (!node) return;
        depth++;
        max_depth = max(max_depth, depth);

        traversal(node->left, depth);
        traversal(node->right, depth);
    }

    int maxDepth(TreeNode* root) {
        traversal(root, 0);
        return max_depth;
    }
};
