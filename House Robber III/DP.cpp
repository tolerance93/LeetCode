/**
 * Runtime: 8 ms, faster than 99.17% of C++ online submissions for House Robber III.
 * Memory Usage: 24.8 MB, less than 53.42% of C++ online submissions for House Robber III.
 */

#include <iostream>
#include <unordered_map>

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
    
    int robSub(TreeNode* node)
    {
        if (!node) return 0;
        if (hashMap.find(node) != hashMap.end()) return hashMap[node];
        
        int robCur = 0;
        
        if (node->left)
        {
            robCur += robSub(node->left->left) + robSub(node->left->right);
        }
        if (node->right)
        {
            robCur += robSub(node->right->left) + robSub(node->right->right);
        }
        robCur += node->val;
        robCur = max(robCur, robSub(node->left) + robSub(node->right));
        hashMap[node] = robCur;
        return robCur;
    }
    
    int rob(TreeNode* root) {
        int res = robSub(root);
        return res;
    }
private:
    unordered_map<TreeNode*, int> hashMap;
};


