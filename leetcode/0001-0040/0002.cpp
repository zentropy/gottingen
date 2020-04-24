/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#define ADD_DIGIT(VALUE) \
    ListNode* n = new ListNode((VALUE)%10);   \
    if(NULL != prev) prev->next = n; \
    else head = n;  \
    carry = (VALUE)/10;  \
    prev = n;   \
    \
\

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        unsigned int carry = 0;
        ListNode* head = NULL,*prev = NULL,*p = l1,*q = l2;
        for(;p != NULL && q != NULL;p = p->next,q = q->next)
        {
            int v = p->val + q->val + carry;
            ADD_DIGIT(v);
        }
        for(;p != NULL;p = p->next)
        {
            int v = p->val + carry;
            ADD_DIGIT(v);
        }
        for(;q != NULL;q = q->next)
        {
            int v = q->val + carry;
            ADD_DIGIT(v);
        }
        if(0 != carry)
        {
            ADD_DIGIT(carry);
        }
        return head;
    }
};