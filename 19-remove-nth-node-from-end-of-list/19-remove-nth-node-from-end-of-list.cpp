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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == 0)
            return 0;
        
        ListNode* hare = head;
        ListNode* tortoise = head;
        int count = 1;
        while(count <= n && hare){
            hare = hare->next;
            count++;
        }
        if(hare){
            
                while(hare->next){
                    hare = hare->next;
                    tortoise = tortoise->next;
                }
                tortoise->next = tortoise->next->next;
            
        }
        else
            return head->next;
        
        return head;
    }
};