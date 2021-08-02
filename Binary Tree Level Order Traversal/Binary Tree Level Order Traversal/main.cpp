/**
 * Runtime: 8 ms, faster than 38.80% of C++ online submissions for Binary Tree Level Order Traversal.
 * Memory Usage: 12.5 MB, less than 83.11% of C++ online submissions for Binary Tree Level Order Traversal.
 */

#include <vector>
#include <queue>

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> > v;
        if (root == nullptr) return v;
        vector<int> temp;
        
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        
        while (!q.empty())
        {
            TreeNode* f = q.front();
            q.pop();
            if (f == nullptr)
            {
                v.push_back(temp);
                temp.clear();
                if (!q.empty())
                {
                    q.push(nullptr);
                }
            }
            else
            {
                temp.push_back(f->val);
                if (f->left) q.push(f->left);
                if (f->right) q.push(f->right);
            }
        }
        
        return v;
    }
};

int main()
{
    return 0;
}
