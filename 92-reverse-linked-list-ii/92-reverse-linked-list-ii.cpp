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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==0) return 0;
        
        ListNode* cur = head, *prev=0;
            while(left>1)
            {
                prev=cur;
                cur=cur->next;
                left--;
                right--;
            }
        
        ListNode* start = prev, *tail=cur;
        ListNode* temp = 0;
        while(right>0)
        {
            temp = cur->next;
            cur->next=prev;
            prev=cur;
            cur=temp;
            right--;
        }
        
        if(start!=0){
            start->next=prev;
        }
        else
        {
            head=prev;
        }
        tail->next=cur;
        return head;
    }
};