/**
 * Runtime: 32 ms, faster than 94.84% of C++ online submissions for Merge Two Binary Trees.
 * Memory Usage: 34.3 MB, less than 25.81% of C++ online submissions for Merge Two Binary Trees.
 */

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2) return nullptr;
        TreeNode* res = new TreeNode();
        
        if (root1) res->val += root1->val;
        if (root2) res->val += root2->val;
        
        TreeNode* left1 = root1 != nullptr ? root1->left : nullptr;
        TreeNode* left2 = root2 != nullptr ? root2->left : nullptr;
        res->left = mergeTrees(left1, left2);
        
        TreeNode* right1 = root1 != nullptr ? root1->right : nullptr;
        TreeNode* right2 = root2 != nullptr ? root2->right : nullptr;
        res->right = mergeTrees(right1, right2);
        
        return res;
    }
};

int main()
{
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(3);
    root1->left->left = new TreeNode(5);
    root1->right = new TreeNode(2);
    
    TreeNode* root2 = new TreeNode(2);
    root2->left = new TreeNode(1);
    root2->right = new TreeNode(3);
    root2->left->right = new TreeNode(4);
    root2->right->right = new TreeNode(7);
    
    Solution sol;
    sol.mergeTrees(root1, root2);
    
    return 0;
}

