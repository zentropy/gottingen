/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(NULL == l1 && NULL == l2) return NULL;
        if(NULL == l1) return l2;
        if(NULL == l2) return l1;
        ListNode* p = l1,*q = l2,*head = NULL,*curr = NULL;
        if(p->val < q->val)
        {
            head = p;
            p = p->next;
        }
        else
        {
            head = q;
            q = q->next;
        }
        curr = head;
        for(;NULL != p && NULL != q;)
        {
            if(p->val < q->val)
            {
                curr->next = p;
                curr = p;
                p = p->next;
            }
            else
            {
                curr->next = q;
                curr = q;
                q = q->next;
            }
        }
        if(NULL != p) curr->next = p;
        if(NULL != q) curr->next = q;
        return head;
    }
};