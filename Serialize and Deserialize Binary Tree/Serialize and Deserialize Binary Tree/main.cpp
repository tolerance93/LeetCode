/**
 * Runtime: 32 ms, faster than 99.13% of C++ online submissions for Serialize and Deserialize Binary Tree.
 * Memory Usage: 31 MB, less than 80.76% of C++ online submissions for Serialize and Deserialize Binary Tree.
 */

#include <string>
#include <iostream>
#include <sstream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode * right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    string serialize(TreeNode* root) {
            ostringstream out;
            serialize(root, out);
            return out.str();
    }

    TreeNode* deserialize(string data) {
        istringstream in(data);
        return deserialize(in);
    }
    
private:
    void serialize(TreeNode* root, ostringstream& out) {
        if (root) {
            // space makes break
            out << root->val << ' ';
            serialize(root->left, out);
            serialize(root->right, out);
        } else {
            out << "# ";
        }
    }

    TreeNode* deserialize(istringstream& in) {
        string val;
        in >> val;
        if (val == "#")
            return nullptr;
        TreeNode* root = new TreeNode(stoi(val));
        root->left = deserialize(in);
        root->right = deserialize(in);
        return root;
    }
    
};

int main()
{
    return 0;
}
