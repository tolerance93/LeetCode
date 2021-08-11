/**
 * Runtime: 12 ms, faster than 48.79% of C++ online submissions for Diameter of Binary Tree.
 * Memory Usage: 20.3 MB, less than 63.69% of C++ online submissions for Diameter of Binary Tree.
 */

#include <algorithm>
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
    
    int updateMax(TreeNode* root, int& ans)
    {
        if (root == nullptr) return 0;
        
        int leftLen = updateMax(root->left, ans);
        int rightLen = updateMax(root->right, ans);
        int cur = leftLen + rightLen;
        
        ans = cur > ans ? cur : ans;
        return max(leftLen, rightLen) + 1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        updateMax(root, ans);
        return ans;
    }
};

int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    
    Solution sol;
    sol.diameterOfBinaryTree(root);
    return 0;
}
