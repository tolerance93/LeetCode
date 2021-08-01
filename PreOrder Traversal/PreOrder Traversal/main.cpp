/**
 * Runtime: 4 ms, faster than 49.13% of C++ online submissions for Binary Tree Preorder Traversal.
 * Memory Usage: 8.4 MB, less than 76.20% of C++ online submissions for Binary Tree Preorder Traversal.
 */

class Solution {
public:
    
    void preorder(TreeNode* node, vector<int>& ans)
    {
        if (!node) return;
        ans.push_back(node->val);
        preorder(node->left, ans);
        preorder(node->right, ans);
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        inorder(root, ans);
        return ans;
    }
};
