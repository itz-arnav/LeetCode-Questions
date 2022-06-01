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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = 0;
        ListNode* curr = head;
        ListNode* next = head;
        while(next){
            curr = next;
            next = next->next;
            curr->next = prev;
            prev = curr;
        }
        return curr;
    }
};