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
    ListNode* swapPairs(ListNode* head) {
        if(NULL == head) return NULL;
        if(NULL == head->next) return head;
        ListNode* pHead = head->next,*prev = NULL;
        for(ListNode* p = head;NULL != p;)
        {
            if(NULL == p->next)
            {
                if(NULL != prev) prev->next = p;
                p = p->next;
            }
            else
            {
                ListNode* next = p->next,*t = p->next->next;
                next->next = p;
                p->next = t;
                if(NULL != prev) prev->next = next;
                prev = p;
                p = t;
            }
        }
        return pHead;
    }
};