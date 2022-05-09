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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* ans = 0;
        ListNode* ptr = ans;
        ListNode* temp = head;
        while(head != 0){
            while(head and head->val == 0)
            head = head->next;
            if(head == 0)
                break;
            temp = head;
            int x = temp->val;
            temp = temp->next;
            while(temp and temp->val != 0){
                x += temp->val;
                temp  = temp->next;
            }
            if(ans == 0){
                ans = new ListNode(x);
                ptr = ans;
            }
            else{
                ptr->next = new ListNode(x);
                ptr = ptr->next;
            }
            head = temp;
        }
        return ans;
    }
};