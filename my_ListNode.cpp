#include <iostream>
#include <vector>
using namespace std;
typedef vector<int>::iterator vecIter;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class my_ListNode {
public:
    ListNode *createLinkedList(vecIter begin,vecIter end)
    {
        ListNode *head = NULL;
        if(begin == end)    return head;
        else    head = new ListNode(*begin++);
        for(ListNode *cur = head; begin != end; cur = cur->next)
            cur->next = new ListNode(*begin++);
        return head;
    }
    void clear(ListNode *head)
    {
        while(head)
        {
            ListNode *del = head;
            head = head->next;
            delete del;
        }
    }
    bool compareTwoLinkedList(ListNode *l1, ListNode *l2)
    {
        for(; l1&&l2; l1=l1->next, l2=l2->next)
            if(l1->val != l2->val)  break;
        return l1 || l2 ? false : true; 
    }
};

int main(int argc, char** argv)
{
    my_ListNode S;
    vector<int> vec1 = {0,3,5};
    vector<int> vec2 = {0,2,3,4};
    vector<int> vec3 = {0,0,2,3,3,4,5};

    ListNode *l1 = S.createLinkedList(vec1.begin(), vec1.end());
    ListNode *l2 = S.createLinkedList(vec2.begin(), vec2.end());
    ListNode *l3 = S.createLinkedList(vec3.begin(), vec3.end());

    S.clear(l1);
    S.clear(l2);
    S.clear(l3);    
}
