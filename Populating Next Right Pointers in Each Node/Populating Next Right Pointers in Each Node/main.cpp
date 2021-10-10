/**
 * Runtime: 12 ms, faster than 98.61% of C++ online submissions for Populating Next Right Pointers in Each Node.
 * Memory Usage: 17.2 MB, less than 37.14% of C++ online submissions for Populating Next Right Pointers in Each Node.
 */

#include <queue>
#define NULL nullptr

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;
    
    Node() : val(0), left(NULL), right(NULL), next(NULL) {}
    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) return nullptr;
        
        Node centinel{1001};
        queue<Node*> queue;
        
        queue.push(root);
        queue.push(&centinel);
        
        while (queue.size() > 0)
        {
            Node* cur = queue.front();
            queue.pop();
            
            if (cur->val == 1001)
            {
                if (queue.size() > 0) queue.push(&centinel);
            }
            else
            {
                cur->next = queue.front()->val == 1001 ? nullptr : queue.front();
                if (cur->left) queue.push(cur->left);
                if (cur->right) queue.push(cur->right);
            }
        }
        return root;
    }
};

int main()
{
    return 0;
}
