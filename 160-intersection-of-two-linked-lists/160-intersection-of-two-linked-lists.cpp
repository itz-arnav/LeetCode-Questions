/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len1 = 0, len2 = 0;
        ListNode* a = headA;
        ListNode* b = headB;
        while(a){
            len1++;
            a = a->next;
        }
        while(b){
            len2++;
            b = b->next;
        }
        if(len1 > len2){
            while(len1 > len2){
                headA = headA->next;
                len1--;
            }
        }
        else{
            while(len2 > len1){
                headB = headB->next;
                len2--;
            }
        }
        while(headA && headB){
                if(headA == headB)
                    return headA;
                headA = headA->next;
                headB = headB->next;
        }
        return 0;
    }
};