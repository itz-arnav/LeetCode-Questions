/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        map<Node*, Node*> mp;
        mp[0] = 0;
        Node* ptr = head;
        while(ptr){
            Node* temp = new Node(ptr->val);
            temp->next = ptr->next;
            mp[ptr] = temp;
            ptr = ptr->next;
        }
        ptr = head;
        while(ptr){
            Node* temp = mp[ptr];
            temp->next = mp[ptr->next];
            temp->random = mp[ptr->random];
            ptr = ptr->next;
        }
        
        
        return mp[head];
    }
};