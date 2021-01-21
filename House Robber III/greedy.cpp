/**
 * Runtime: 32 ms, faster than 34.27% of C++ online submissions for House Robber III.
 * Memory Usage: 41.5 MB, less than 6.18% of C++ online submissions for House Robber III.
 */

#include <iostream>

using namespace std;

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
    shared_ptr<int> robSub(TreeNode* node)
    {
        shared_ptr<int> res ( new int[2], default_delete<int[]>());
        res.get()[0] = res.get()[1] = 0;
        if (!node) return res;
        
        auto left = robSub(node->left);
        auto right = robSub(node->right);
        
        res.get()[0] = node->val + left.get()[1] + right.get()[1];
        res.get()[1] = max(left.get()[0], left.get()[1]) + max(right.get()[0], right.get()[1]);
        
        return res;
    }
    
    int rob(TreeNode* root) {
        auto res = robSub(root);
        return max(res.get()[0], res.get()[1]);
    }
};
