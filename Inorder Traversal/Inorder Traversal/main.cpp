/**
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions for Binary Tree Inorder Traversal.
 * Memory Usage: 8.4 MB, less than 61.60% of C++ online submissions for Binary Tree Inorder Traversal.
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right): val(x), left(left), right(right) {}
};

class Solution {
public:
    
    void inorder(TreeNode* node, vector<int>& ans)
    {
        if (!node) return;
        inorder(node->left, ans);
        ans.push_back(node->val);
        inorder(node->right, ans);
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inorder(root, ans);
        return ans;
    }
};
