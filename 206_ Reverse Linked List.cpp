/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 1:
 
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL) return NULL;
        ListNode *pre=NULL,*now=head,*after = NULL;
        while(now!=NULL)
        {
            after = now->next;
            now->next = pre;
            pre = now;
            now = after;
        }
        return pre;
        
    }
};
2:
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next == NULL) return head;
        
        
        ListNode* ret = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return ret;
    }
};