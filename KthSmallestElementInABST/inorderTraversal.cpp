/**
 * Runtime: 16 ms, faster than 98.37% of C++ online submissions for Kth Smallest Element in a BST.
 * Memory Usage: 24.2 MB, less than 99.94% of C++ online submissions for Kth Smallest Element in a BST.
 */

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void traverse(TreeNode* node , int k)
    {
        if (!node || count == k) return;
        traverse(node->left, k);
        count++;
        if (count == k)
        {
            result = node->val;
            return;
        }
        traverse(node->right, k);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        result = 0;
        count = 0;
        traverse(root, k);
        return result;
    }
    
private:
    int result;
    int count;
};
