/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
        if(a == 0)
            return b;
        if(b == 0)
            return a;
        
        ListNode* head = 0;
        if(a->val <= b->val){
            head = a;
            a = a->next;
        }
        else{
            head = b;
            b = b->next;
        }
        ListNode* curr = head;
        
        while(a and b){
            if(a->val <= b->val){
                curr->next = a;
                a = a->next;
            }
            else{
                curr->next = b;
                b = b->next;
            }
            curr = curr->next;
        }
        while(a)
        {
            curr->next = a;
            a = a->next;
            curr = curr->next;
        }
        while(b){
            curr->next = b;
            b = b->next;
            curr = curr->next;
        }
        curr->next = 0;
        return head;
    }
};