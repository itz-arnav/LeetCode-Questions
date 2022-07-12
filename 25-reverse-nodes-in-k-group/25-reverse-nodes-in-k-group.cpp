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
    
    void rev(ListNode* s, ListNode* e){
         ListNode* p = 0;
         ListNode*c = s;
         ListNode*n = s->next;
        
         while(p!=e){
             c->next = p;
             p = c;
             c = n;
             if(n!=0)
             n = n->next;
         }
        
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == 0 || head->next == 0 || k == 1)
            return head;
        
        ListNode* s = head;
        ListNode* e = head;
        int inc = k-1;
        while(inc--){
            
            e = e->next;
            if(e==0)
                return head;
        }
        
        ListNode* temp = reverseKGroup(e->next, k);
        rev(s, e);
        
        s->next = temp;
        
        return e;
    }
};