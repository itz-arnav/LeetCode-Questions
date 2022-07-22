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
    ListNode* partition(ListNode* head, int x) {
        if(head == 0 || head->next == 0)
            return head;
        ListNode* less = 0;
        ListNode* greater = 0;
        ListNode* curr = head;
        ListNode* firstgreat = 0;
        
        while(curr){
            if(curr->val >= x){
                if(firstgreat == 0){
                    firstgreat = curr;
                    greater = curr;
                }
                else{
                    greater->next = curr;
                    greater = greater->next;
                }
            }
            else{
                if(less == 0){
                    less = curr;
                    head = curr;
                }
                else{
                    less->next = curr;
                    less = less->next;
                }
            }
            curr = curr->next;
        }
        if(!less)
            return firstgreat;
            
        
        
        less->next = firstgreat;
        if(greater)
        greater->next = 0;
        
        return head;
        
    }
};