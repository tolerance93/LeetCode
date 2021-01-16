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
    TreeNode* invertTree(TreeNode* root) {
        queue<TreeNode*> q;
        if (root) q.push(root);
        
        while (q.size())
        {
            TreeNode* cur = q.front();
            q.pop();
            
            TreeNode* temp = cur->left;
            cur->left = cur->right;
            cur->right = temp;
            
            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);
        }
        return root;
    }
};
