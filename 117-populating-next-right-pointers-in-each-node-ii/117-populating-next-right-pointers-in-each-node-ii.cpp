/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
    if(!root) return NULL;
    
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        int s=q.size();
        Node *prev=new Node();
        while(s)
        {
            Node*cur=q.front();
            q.pop();
            if(cur->left) q.push(cur->left);
            if(cur->right) q.push(cur->right);
            if(s==1)
            {
                prev->next=cur;
                prev=cur;
                cur->next=NULL;
                break;
            }
            prev->next=cur;
            prev=cur;
            
            
            --s;
        }
    }
    return root;
}
};