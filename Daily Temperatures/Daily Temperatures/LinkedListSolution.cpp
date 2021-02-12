#include <vector>
#include <iostream>
using namespace std;
/**
 * Linked list solution
 */

class Solution2
{
private:
    const static int MAX_TEMPARATUE = 100;
    const static int NULL_INDEX = 40000;
    struct Node
    {
        int pos;
        Node* next;
    };
    struct NodeList
    {
        Node* head;
        Node* tail;
        
        NodeList() : head(0), tail(0) {}
        NodeList(Node* head, Node* tail) : head(head), tail(tail) {}
    };
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int n = T.size();
        NodeList tempatatures[MAX_TEMPARATUE + 1];
        vector<int> res;
        
        for (int i = 0; i < MAX_TEMPARATUE + 1; i++)
        {
            tempatatures[i] = {0, 0};
        }
        
        for (int i = 0; i < n; i++)
        {
            Node* node = new Node;
            node->next = 0;
            node->pos = i;
            
            if (tempatatures[T[i]].tail)
            {
                tempatatures[T[i]].tail->next = node;
                tempatatures[T[i]].tail = node;
            }
            else
            {
                tempatatures[T[i]].head = node;
                tempatatures[T[i]].tail = node;
            }
        }
        
        for (int i = 0; i < n; i++)
        {
            int pos = NULL_INDEX;
            for (int j = T[i] + 1; j <= 100; j++)
            {
                if (tempatatures[j].head)
                {
                    Node* prev = 0;
                    Node* cur = tempatatures[j].head;
                    while (cur && cur->pos <= i)
                    {
                        prev = cur;
                        cur = cur->next;
                        delete prev;
                        prev = 0;
                    }
                    tempatatures[j].head = cur;
                    if (!cur) tempatatures[j].tail = 0;
                    
                    if (cur && cur->pos < pos) pos = cur->pos;
                }
            }
            if (pos != NULL_INDEX) res.push_back(pos - i);
            else res.push_back(0);
        }
        //Prevent memory leak
        for (int i = 0; i < MAX_TEMPARATUE + 1; i++)
        {
            if (tempatatures[i].head)
            {
                Node* prev = 0;
                Node* cur = tempatatures[i].head;
                while (cur)
                {
                    prev = cur;
                    cur = cur->next;
                    delete prev;
                }
            }
        }
        return res;
    }
};

int main1234()
{
    vector<int> input = {73,74,75,71,69,72,76,73};
    Solution2 sol;
    vector<int> res = sol.dailyTemperatures(input);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << endl;
    }
    return 0;
}
