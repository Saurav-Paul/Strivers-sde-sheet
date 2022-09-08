//https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
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
        
        if(root == NULL) return root;
        
        queue<Node*> q;
        Node* head = root;
        
        q.push(root);

        while(!q.empty()){
            int sz = q.size() ;
            
            Node* prev = NULL;
            
            while(sz--){
                Node* node = q.front();
                q.pop();

                if(prev != NULL) prev->next = node;
                prev = node;
                
                if(node->left != NULL) q.push(node->left);
                if(node->right != NULL) q.push(node->right);
            }
        }
        
        return head;
    }
};
