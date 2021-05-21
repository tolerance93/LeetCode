/**
 * Runtime: 12 ms, faster than 56.64% of C++ online submissions for Validate Binary Search Tree.
 * Memory Usage: 21.6 MB, less than 41.43% of C++ online submissions for Validate Binary Search Tree.
 *
 * 1. [MIN_INT]의 edge case처리가 가능하면서 깔끔한 초깃값을 설정할 수 있을까?
 * 2. Iterative로 풀수도 있을 듯
 */

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int prev = -987654321;
    bool isValid = true;
    
    bool isValidBST(TreeNode* root) {
        if (root == 0) return true;
        
        if (!isValid) return false;
        isValid = isValidBST(root->left);
        
        if (prev != -987654321)
        {
            if (root->val <= prev) isValid = false;
        }
        prev = root->val;
        
        isValid = isValid && isValidBST(root->right);

        return isValid;
    }
};
