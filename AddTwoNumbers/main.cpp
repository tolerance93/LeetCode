//
//  main.cpp
//  AddTwoNumbers
//
//  Created by Tolerance on 2020/12/25.
//


  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* cur = new ListNode(0, 0);
        ListNode* res = cur;
        
        int a,b,sum;
        int carry = 0;
        
        while (true)
        {
            if (!l1 && !l2) break;
            
            a = 0;
            b = 0;
            sum = 0;
            
            if (l1) a = l1->val;
            if (l2) b = l2->val;
            
            sum = (a + b + carry) % 10;
            carry = (a + b + carry) / 10;
            
            cur->val = sum;
            
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
            
            if ((l1 || l2) || carry)
            {
                cur->next = new ListNode(carry, 0);
                cur = cur->next;
            }
        }
        return cur;
    }
};


#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
