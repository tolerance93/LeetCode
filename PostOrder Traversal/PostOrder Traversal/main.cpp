/**
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions for Binary Tree Postorder Traversal.
  *Memory Usage: 8.5 MB, less than 35.72% of C++ online submissions for Binary Tree Postorder Traversal.
 */

class Solution {
public:
    
    void postorder(TreeNode* node, vector<int>& ans)
    {
        if (!node) return;
        postorder(node->left, ans);
        postorder(node->right, ans);
        ans.push_back(node->val);
    }
    
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        postorder(root, ans);
        return ans;
    }
};
