/**
 * Runtime: 1100 ms, faster than 5.02% of C++ online submissions for House Robber III.
 * Memory Usage: 22.1 MB, less than 99.67% of C++ online submissions for House Robber III.
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
    int recur(TreeNode* node, bool rob)
    {
        if (!node->left && !node->right)
        {
            if (rob) return node->val;
            else return 0;
        }
        if (rob)
        {
            int a = 0;
            int b = 0;
            if (node->left) a = recur(node->left, false);
            if (node->right) b = recur(node->right, false);
            return a + b + node->val;
        }
        else
        {
            int a = 0;
            int b = 0;
            int c = 0;
            int d = 0;
            
            if (node->left)
            {
                a = recur(node->left, true);
                c = recur(node->left, false);
            }

            if (node->right)
            {
                b = recur(node->right, true);
                d = recur(node->right, false);
            }
            return max(a,c) + max(b,d);
        }
    }
    
    int rob(TreeNode* root) {
        if (!root) return 0;
        int a = recur(root, false);
        int b = recur(root, true);
        return max(a,b);
    }
};
