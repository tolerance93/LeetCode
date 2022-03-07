#include <iostream>

using namespace std;

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
    
    Node(int n)
    {
        val = n;
        prev = nullptr;
        next = nullptr;
        child = nullptr;
    }
};

class Solution {
public:
    
    Node* flatAndReturnEnd(Node* cur)
    {
        Node* temp;
        Node* end;
        Node* prev = nullptr;
        
        while (cur != nullptr)
        {
            prev = cur;
            if (cur->child != nullptr)
            {
                temp = cur->next;
                
                cur->next = cur->child;
                cur->child->prev = cur;
                
                end = flatAndReturnEnd(cur->child);
                cur->child = nullptr;
                
                if (temp != nullptr) temp->prev = end;
                end->next = temp;
                cur = temp;
                prev = end;
            }
            else
            {
                cur = cur->next;
            }
        }
        return prev;
    }
    
    Node* flatten2(Node* head) {
        Node* cur = head;
        flatAndReturnEnd(cur);
        return head;
    }
    
    Node* flatten(Node* head)
    {
        Node* cur = head;
        while (cur != nullptr)
        {
            if (cur->child == nullptr)
            {
                cur = cur->next;
                continue;
            }
            Node* childEnd = cur->child;
            while (childEnd->next != nullptr) childEnd = childEnd->next;
            
            if (cur->next != nullptr) cur->next->prev = childEnd;
            childEnd->next = cur->next;
            
            cur->next = cur->child;
            cur->child->prev = cur;
            cur->child = nullptr;
            
            cur = cur->next;
        }
        return head;
    }
};

int main()
{
    Node* one = new Node(1);
    Node* two = new Node(2);
    Node* three = new Node(3);
    one->child = two;
    two->child = three;
    Solution sol;
    sol.flatten(one);
    while (one)
    {
        cout << one->val << endl;
        one = one->next;
    }
    return 0;
}
