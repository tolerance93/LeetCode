/**
 * Runtime: 16 ms, faster than 77.06% of C++ online submissions for Path Sum III.
 * Memory Usage: 15.5 MB, less than 90.85% of C++ online submissions for Path Sum III.
 */


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    
    void dfs(TreeNode* root, int targetSum, int& ans, int cur)
    {
        if (root == nullptr) return;
        cur += root->val;
        if (cur == targetSum) ans++;
        dfs(root->left, targetSum, ans, cur);
        dfs(root->right, targetSum, ans, cur);
    }
    
    void inorderTraverse(TreeNode* root, int targetSum, int& ans)
    {
        if (root == nullptr) return;
        dfs(root, targetSum, ans, 0);
        inorderTraverse(root->left, targetSum, ans);
        inorderTraverse(root->right, targetSum, ans);
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        int ans = 0;
        inorderTraverse(root, targetSum, ans);
        return ans;
    }
};

int main()
{
    return 0;
}
