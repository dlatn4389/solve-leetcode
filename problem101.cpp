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
private:
    bool checkSymmetric(TreeNode* left, TreeNode* right) {
        if (!left and !right) return true;
        if (!left and right) return false;
        if (left and !right) return false;

        if (left->val != right->val) return false;
        return checkSymmetric(left->right, right->left) && checkSymmetric(left->left, right->right);
    }
public:
    bool isSymmetric(TreeNode* root) {
        return checkSymmetric(root->left, root->right);
    }
};