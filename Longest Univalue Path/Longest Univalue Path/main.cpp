/**
 * Runtime: 192 ms, faster than 23.86% of C++ online submissions for Longest Univalue Path.
 * Memory Usage: 71.9 MB, less than 44.78% of C++ online submissions for Longest Univalue Path.
 */
#include <unordered_set>

using namespace std;

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
    
    void findPath(TreeNode* node, int path, int& longest)
    {
        if (path > longest) longest = path;
        if (node->left && node->left->val == node->val)
        {
            findPath(node->left, path + 1, longest);
        }
        if (node->right && node->right->val == node->val)
        {
            findPath(node->right, path + 1, longest);
        }
    }
    
    int search(TreeNode* node, int path)
    {
        int left = 0;
        int right = 0;
        if (node->left && node->left->val == node->val)
        {
            findPath(node->left, 1, left);
        }
        if (node->right && node->right->val == node->val)
        {
            findPath(node->right, 1, right);
        }
        return left + right;
    }
    
    void preorder(TreeNode* node, int& res)
    {
        if (node == nullptr) return;
        res = max(res, search(node, 0));
        preorder(node->left, res);
        preorder(node->right, res);
    }
    
    int longestUnivaluePath(TreeNode* root) {
        int res = 0;
        preorder(root, res);
        return res;
    }
};

int main()
{
    return 0;
}
