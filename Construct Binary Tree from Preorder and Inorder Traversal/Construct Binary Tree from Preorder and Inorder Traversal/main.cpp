/**
 * Runtime: 40 ms, faster than 28.61% of C++ online submissions for Construct Binary Tree from Preorder and Inorder Traversal.
 * Memory Usage: 26 MB, less than 76.89% of C++ online submissions for Construct Binary Tree from Preorder and Inorder Traversal.
 */

#include <vector>

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int preStart, int preEnd, int inStart, int inEnd)
    {
        if (preStart >= preEnd || inStart >= inEnd) return nullptr;
        TreeNode* node = new TreeNode(preorder[preStart]);
        int index = - 1;
        for (int i = inStart; i < inorder.size(); i++)
        {
            index++;
            if (inorder[i] == preorder[preStart]) break;
        }
        node->left = buildTree(preorder, inorder, preStart + 1, preStart + index + 1, inStart, inStart + index);
        node->right = buildTree(preorder, inorder, preStart + index + 1, preEnd, inStart + index + 1, inEnd);
        return node;
    }
    
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0) return nullptr;
        TreeNode* root = buildTree(preorder, inorder, 0, preorder.size(), 0, inorder.size());
        return root;
    }
};

int main()
{
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};
    Solution sol;
    TreeNode* root = sol.buildTree(preorder, inorder);
    return 0;
}
