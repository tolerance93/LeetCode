/**
 * Runtime: 4 ms, faster than 64.50% of C++ online submissions for Binary Tree Right Side View.
 * Memory Usage: 12.1 MB, less than 21.22% of C++ online submissions for Binary Tree Right Side View.
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        
        if (root == nullptr) return ans;
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
                ans.push_back(temp[temp.size() - 1]);
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
        return ans;
    }
};

int main()
{
    return 0;
}
