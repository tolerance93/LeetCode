/**
 * Runtime: 16 ms, faster than 80.89% of C++ online submissions for Construct Binary Tree from Preorder and Inorder Traversal.
 * Memory Usage: 26.5 MB, less than 28.69% of C++ online submissions for Construct Binary Tree from Preorder and Inorder Traversal.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */

#include <vector>
#include <unordered_map>

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int preStart, int preEnd, int inStart, int inEnd, unordered_map<int, int>& inorderMap)
    {
        if (preStart >= preEnd || inStart >= inEnd) return nullptr;
        TreeNode* node = new TreeNode(preorder[preStart]);
        int rootIdxAtInorder = inorderMap[preorder[preStart]];
        int leftSubTreeCount = rootIdxAtInorder - inStart;
        
        node->left = buildTree(preorder, inorder, preStart + 1, preStart + leftSubTreeCount + 1, inStart, inStart + leftSubTreeCount, inorderMap);
        node->right = buildTree(preorder, inorder, preStart + leftSubTreeCount + 1, preEnd, inStart + leftSubTreeCount + 1, inEnd, inorderMap);
        return node;
    }
    
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0) return nullptr;
        unordered_map<int, int> inorderMap;
        for (int i = 0; i < inorder.size(); i++)
        {
            inorderMap[inorder[i]] = i;
        }
        TreeNode* root = buildTree(preorder, inorder, 0, preorder.size(), 0, inorder.size(), inorderMap);
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
