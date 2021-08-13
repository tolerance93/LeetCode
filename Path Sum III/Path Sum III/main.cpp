/** Brute force
 * Runtime: 16 ms, faster than 77.06% of C++ online submissions for Path Sum III.
 * Memory Usage: 15.5 MB, less than 90.85% of C++ online submissions for Path Sum III.
 */

/** DP
 * Runtime: 7 ms, faster than 98.95% of C++ online submissions for Path Sum III.
 * Memory Usage: 18.7 MB, less than 38.59% of C++ online submissions for Path Sum III.
 */
#include <unordered_map>

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
    
    void dfs(TreeNode* root, int targetSum, int& ans, unordered_map<int, int>& dp, int cur)
    {
        if (root == nullptr) return;
        cur += root->val;
        if (dp.find(cur - targetSum) != dp.end())
        {
            ans += dp[cur - targetSum];
        }
        if (dp.find(cur) != dp.end()) dp[cur] += 1;
        else dp[cur] = 1;
        dfs(root->left, targetSum, ans, dp, cur);
        dfs(root->right, targetSum, ans, dp, cur);
        dp[cur] -= 1; // backtracking. 원래대로 돌려놓기
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        int ans = 0;
        unordered_map<int, int> dp;
        dp[0] = 1;
        dfs(root, targetSum, ans, dp, 0);
        return 0;
    }
    
//    void dfs(TreeNode* root, int targetSum, int& ans, int cur)
//    {
//        if (root == nullptr) return;
//        cur += root->val;
//        if (cur == targetSum) ans++;
//        dfs(root->left, targetSum, ans, cur);
//        dfs(root->right, targetSum, ans, cur);
//    }
//
//    void inorderTraverse(TreeNode* root, int targetSum, int& ans)
//    {
//        if (root == nullptr) return;
//        dfs(root, targetSum, ans, 0);
//        inorderTraverse(root->left, targetSum, ans);
//        inorderTraverse(root->right, targetSum, ans);
//    }
//
//    int pathSum(TreeNode* root, int targetSum) {
//        int ans = 0;
//        inorderTraverse(root, targetSum, ans);
//        return ans;
//    }
};

int main()
{
    return 0;
}
