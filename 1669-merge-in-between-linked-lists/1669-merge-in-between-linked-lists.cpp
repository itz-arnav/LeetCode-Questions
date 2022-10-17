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
    ListNode* mergeInBetween(ListNode* head, int a, int b, ListNode* copy) {
        ListNode* ptr = head;
        int count = 1;
        while(ptr){
            if(count == a){
                ListNode* temp = ptr->next;
                ptr->next = copy;
                ptr = temp;
                count++;
            }
            else if(count == b+1){
                while(copy->next){
                    copy = copy->next;
                }
                copy->next = ptr->next;
                return head;
            }
            else{
                ptr = ptr->next;
                count++;
            }
        }
        return head;
    }
};