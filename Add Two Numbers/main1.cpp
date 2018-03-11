#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *ret = new ListNode(0);
        ListNode *cur = ret;
        int sum = 0;
        while (1) {
            if (l1->next != NULL) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2->next != NULL) {
                sum += l2->val;
                l2 = l2->next;
            }
            cur->val = sum % 10;
            sum /= 10;

            if (l1->next != NULL || l2->next != NULL || sum)
                cur = (cur->next = new ListNode(0));
            else
                break;
        }
        return ret;
    }
};

ListNode *addValAndCreateNewNode(ListNode *cur, int val) {
    cur->val = val;
    cur->next = new ListNode(0);
    return cur->next;
}

int main(int argc, char** argv)
{
    Solution s;
    ListNode *a = new ListNode(0), *b = new ListNode(0);
    ListNode *pa = a, *pb = b;
    pa = addValAndCreateNewNode(pa, 2);
    pa = addValAndCreateNewNode(pa, 4);
    pa = addValAndCreateNewNode(pa, 3);
    pb = addValAndCreateNewNode(pb, 5);
    pb = addValAndCreateNewNode(pb, 6);
    pb = addValAndCreateNewNode(pb, 4);
    ListNode *res = s.addTwoNumbers(a, b);
    while(res)
    {
        cout << res->val << endl;
        res = res->next;
    }
    return 0;
}
