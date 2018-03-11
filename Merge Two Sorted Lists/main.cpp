#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *p1 = l1, *p2 = l2;
        ListNode *head = NULL, **p = &head;
        for(; p1&&p2; p = &(*p)->next)
        {
            if(p1->val < p2->val)
            {
                *p = p1;
                // *p = new ListNode(p1->val);
                p1 = p1->next;
            }
            else
            {
                *p = p2;
                // *p = new ListNode(p2->val);
                p2 = p2->next;
            }
        }
        *p = p1 ? p1 : p2;
        return head;
    }
    ListNode *mergeTwoLists01(ListNode* head1, ListNode* head2)
    {
        ListNode *p1 = head1,  *p2=head2;
        ListNode dummy(0);
    
        dummy.next = p1;
        ListNode *prev = &dummy;
    
        while(p1 && p2){
            if(p1->val < p2->val){
                prev->next = p1;
                p1 = p1->next;
                prev = prev->next;
            }else{
                prev->next = p2;
                p2 = p2->next;
                prev = prev->next;
                prev->next = p1;
            }
        }
        if(p1) prev->next = p1;
        else prev->next = p2;
        return dummy.next;
    }
};

int main(int argc, char** argv)
{
     
}
