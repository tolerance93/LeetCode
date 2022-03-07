/**
 Runtime: 3 ms, faster than 69.23% of C++ online submissions for Reverse Linked List II.
 Memory Usage: 7.4 MB, less than 93.56% of C++ online submissions for Reverse Linked List II.
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseBetween2(ListNode* head, int left, int right) {
        if (left == right) return head;
        ListNode* leftNode = head;
        ListNode* rightNode = head;
        ListNode* leftPrevNode = nullptr;
        ListNode* rightNextNode = nullptr;
        
        for (int i = 1; i < left; i++)
        {
            leftPrevNode = leftNode;
            leftNode = leftNode->next;
        }
        
        for (int i = 1; i < right; i++)
        {
            rightNode = rightNode->next;
        }
        
        if (left == 1) head = rightNode;
        
        rightNextNode = rightNode->next;
        
        ListNode* leftNextNode = leftNode->next;
        ListNode* temp;
        
        if (leftPrevNode != nullptr) leftPrevNode->next = rightNode;
        leftNode->next = rightNextNode;
        
        while (true)
        {
            temp = leftNextNode->next;
            leftNextNode->next = leftNode;
            leftNode = leftNextNode;
            leftNextNode = temp;
            if (leftNode == rightNode) break;
        }
        
        return head;
    }
    
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy;
        for (int i = 0; i < left - 1; i++)
        {
            prev = prev->next;
        }
        
        ListNode* curNode = prev->next;
        ListNode* nextNode = curNode->next;
        
        for (int i = 0; i < right - left; i++)
        {
            curNode->next = nextNode->next;
            nextNode->next = prev->next;
            prev->next = nextNode;
            nextNode = curNode->next;
        }
        return dummy->next;
    }

};

int main()
{
    return 0;
}
