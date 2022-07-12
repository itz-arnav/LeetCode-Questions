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
    
    ListNode* rev(ListNode *head){
        if(head == 0 || head->next == 0){
            return head;
        }
        ListNode *temp = rev(head->next);
        head->next->next = head;
        head->next = 0;
        return temp;
    }
    bool isPalindrome(ListNode* head) {
        ListNode *hare = head;
        ListNode *tortoise = head;
        while(hare && hare->next){
            hare = hare->next->next;
            tortoise = tortoise->next;
        }
        tortoise = rev(tortoise);
        hare = head;
        while(tortoise && hare){
            if(tortoise->val != hare->val){
                return false;
            }
            tortoise = tortoise->next;
            hare = hare->next;
            
        }
        return true;
    }
};