/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include "iostream"

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (root != nullptr)
        {
            if (root->val > p->val && root->val > q->val) root = root->left;
            else if (root->val < p->val && root->val < q->val) root = root->right;
            else return root;
        }
        return nullptr;
    }
};

int main()
{
    TreeNode* head = new TreeNode(3);
    head->left = new TreeNode(5);
    head->right = new TreeNode(1);
    head->left->left = new TreeNode(6);
    head->left->right = new TreeNode(2);
    head->left->right->left = new TreeNode(7);
    head->left->right->right = new TreeNode(4);
    head->right->left = new TreeNode(0);
    head->right->right = new TreeNode(8);
    
    Solution sol;
    cout << sol.lowestCommonAncestor(head, head->left, head->left->right->right)->val << endl;
    return 0;
}
