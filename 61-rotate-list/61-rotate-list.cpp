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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == 0 || head->next == 0 || k == 0)
            return head;
        
        ListNode* prev = 0;
        int sz = 0;
        ListNode* ptr = head;
        ListNode* ch = head;
        
        while(ptr){
            sz++;
            ptr = ptr->next;
        }
        
        k %= sz;
        
        if(k == 0)
            return head;
        
        ptr = head;
        cout<<k<<endl;
        
        int i = 1; 
        ListNode* slow = head;
        
        while(i <= k){
            ptr = ptr->next;
            i++;
        }
        cout<<"here "<<ptr->val<<endl;
        while(ptr->next){
            prev = slow;
            slow = slow->next;
            ptr = ptr->next; 
        }
        cout<<"slow : "<<slow->val<<endl;
        head = slow->next;
        slow->next = 0;
        
        ptr->next = ch;
        
        return head;
    }
};