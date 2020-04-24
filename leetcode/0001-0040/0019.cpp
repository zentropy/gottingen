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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(NULL == head) return NULL;
        ListNode* tail = head;
        for(int i = 1;NULL != tail && i < n;tail = tail->next,++i);
        assert(NULL != tail);
        ListNode* curr = head,*prev = NULL;
        for(;NULL != tail->next;curr = curr->next,tail = tail->next) prev = curr;
        if(NULL == prev)
        {
            assert(curr == head);
            return curr->next;
        }
        ListNode* next = prev->next;
        prev->next = next->next;
        return head;
    }
};