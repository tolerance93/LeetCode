/**
 * Runtime: 16 ms, faster than 39.08% of C++ online submissions for Convert Sorted Array to Binary Search Tree.
 * Memory Usage: 21.5 MB, less than 42.15% of C++ online submissions for Convert Sorted Array to Binary Search Tree.
 */

#include <vector>

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
    
    TreeNode* createNode(vector<int>& nums, int start, int end)
    {
        if (start > end) return nullptr;
        int mid = (start + end) / 2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = createNode(nums, start, mid - 1);
        node->right = createNode(nums, mid + 1, end);
        return node;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size() == 0) return nullptr;
        int mid = (nums.size() - 1) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = createNode(nums, 0, mid - 1);
        root->right = createNode(nums, mid + 1, nums.size() - 1);
        return root;
    }
};

int main()
{
    return 0;
}
