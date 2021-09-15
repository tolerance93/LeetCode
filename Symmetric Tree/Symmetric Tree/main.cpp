/**
 * Runtime: 4 ms, faster than 76.89% of C++ online submissions for Symmetric Tree.
 * Memory Usage: 16.4 MB, less than 74.07% of C++ online submissions for Symmetric Tree.
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
    
    bool isSymmetric(TreeNode* left, TreeNode* right)
    {
        if (left == nullptr && right == nullptr) return true;
        if (left == nullptr || right == nullptr) return false;
        if (left->val != right->val) return false;
        return isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        return isSymmetric(root->left, root->right);
    }
};

int main()
{
    return 0;
}
