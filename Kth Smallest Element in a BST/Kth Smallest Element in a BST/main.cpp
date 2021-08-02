/**
 * Runtime: 16 ms, faster than 82.04% of C++ online submissions for Kth Smallest Element in a BST.
 * Memory Usage: 24.1 MB, less than 59.00% of C++ online submissions for Kth Smallest Element in a BST.
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    
    void inorder(TreeNode* root, int &count, int &ans, int k)
    {
        if (root == nullptr) return;
        inorder(root->left, count, ans, k);
        count++;
        if (count == k)
        {
            ans = root->val;
            return;
        }
        inorder(root->right, count, ans, k);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        int ans = 0;
        inorder(root, count, ans, k);
        return ans;
    }
};

int main()
{
    return 0;
}
