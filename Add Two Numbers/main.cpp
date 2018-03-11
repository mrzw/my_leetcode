#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum = 0;
        ListNode *result = NULL;
        ListNode **t = &result;
        while(l1 || l2)
        {
            if(l1)
            {
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2)
            {
                sum += l2->val;
                l2 = l2->next;     
            }
            ListNode *node = new ListNode(sum % 10);
            *t = node;
            t = (&node->next);
            sum /= 10;
        }
        if(sum > 0)
        {
            ListNode *node = new ListNode(sum % 10);
            *t = node;
            t = (&node->next);
        }
        return result; 
    }
};

ListNode *create_linkedlist(std::initializer_list<int> lst)
{
    auto iter = lst.begin();
    ListNode *head = lst.size() ? new ListNode(*iter++) : NULL;
    for (ListNode *cur=head; iter != lst.end(); cur=cur->next)
        cur->next = new ListNode(*iter++);
    return head;
}

int main(int argc, char** argv)
{
    Solution s;
    ListNode *a = create_linkedlist({2,4,3});
    ListNode *b = create_linkedlist({5,6,4});
    ListNode *res = s.addTwoNumbers(a, b);
    while(res)
    {
        cout << res->val << endl;
        res = res->next;
    }
    return 0;
}
