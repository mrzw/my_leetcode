#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL || n<=0) return NULL;
        ListNode fakeHead(0);
        fakeHead.next = head;
        head = &fakeHead;
        ListNode *p1, *p2;
        p1 = head;
        p2 = head;
        for(int i=0; i<n; i++)
        {
            p2 = p2->next;
            if(p2==NULL) return NULL;
        }
        while(p2.next!=NULL)
        {
            p1 = p1->next;
            p2 = p2->next;
        }
        p1->next = p1->next->next;
        return head->next;
    }
};

int main(int argc, char** argv)
{
    
}
