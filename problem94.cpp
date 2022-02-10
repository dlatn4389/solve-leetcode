#include <iostream>
#include <algorithm>
#include <vector>
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
    vector<int> answer;
    void inorder(TreeNode* node) {
        if (node==nullptr) return;
        inorder(node->left);
        answer.push_back(node->val);
        inorder(node->right);
    };
public:
    vector<int> inorderTraversal(TreeNode* root) {
        inorder(root);
        return answer;
    }
};
