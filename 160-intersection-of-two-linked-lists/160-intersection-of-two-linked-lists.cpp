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
 
        unordered_map<ListNode*,bool>mp;
        while(headA!=NULL || headB!=NULL){
            if(headA && mp.find(headA) != mp.end())
                return headA;
            if(headB && mp.find(headB) != mp.end())
                return headB;
            if(headB){
            mp[headB]=1;
            headB= headB->next;
            }
            if(headA && mp.find(headA) != mp.end())
                return headA;
            if(headA){mp[headA]=1;
            headA = headA->next;
            }
            if(headB && mp.find(headB) != mp.end())
                return headB;
    }
        return NULL;
    }
};