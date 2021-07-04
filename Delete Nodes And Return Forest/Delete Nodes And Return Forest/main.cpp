/**
 * Runtime: 20 ms, faster than 80.54% of C++ online submissions for Delete Nodes And Return Forest.
 * Memory Usage: 25.3 MB, less than 76.61% of C++ online submissions for Delete Nodes And Return Forest.
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include "vector"
#include "set"

using namespace std;

class Solution {
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete)
    {
        set<int> to_delete_set;
        vector<TreeNode*> res;
        
        for (auto e : to_delete)
        {
            to_delete_set.insert(e);
        }
        delNode(root, res, to_delete_set, true);
        return res;
    }
private:
    TreeNode* delNode(TreeNode* node, vector<TreeNode*>& res, set<int>& set, bool is_root)
    {
        if (node == nullptr) return nullptr;
        bool del = set.find(node->val) != set.end();
        if (is_root && !del)
        {
            res.push_back(node);
        }
        node->left = delNode(node->left, res, set, del);
        node->right = delNode(node->right, res, set, del);
        if (del) return nullptr;
        return node;
    }
};
