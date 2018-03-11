#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    // 交换数值
    ListNode* swapPairs(ListNode* head) {
        for(ListNode* p=head; p&&p->next; p=p->next->next)
        {
            int temp = p->val;
            p->val = p->next->val;
            p->next->val = temp;
        }
        return head;
    }
    // 交换节点
    ListNode* swapPairs1(ListNode* head) {
        ListNode* h = NULL;
        for(ListNode *p=head; p&&p->next; p=p->next)
        {
            ListNode *n = p->next;
            p->next = n->next;
            n->next = p;
            if(h) h->next = n;
            h = p;
            if(head==p) head = n;
        }
        return head;
    }
};

int main(int argc, char** argv)
{
    
}
