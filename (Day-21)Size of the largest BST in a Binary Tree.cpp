//https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans = 0 ;
    class Node{
        public:
        
        bool is_bst;
        int mx , mn ;
        int val;

        Node(int _mx = INT_MIN,int _mn = INT_MAX,int _val = 0, bool _ok = true){
            mx = _mx ;
            mn = _mn ;
            is_bst = _ok ;
            val = _val ;
        }
    };
    
    Node* traverse(TreeNode* root){
        if(root == NULL) return new Node() ;
        
        Node* x = traverse(root->left) ;
        Node* y = traverse(root->right) ;
        
        bool ok = true ;
        
        if(x->mx >= root->val) ok = false ;
        if(y->mn <= root->val) ok = false;
        if((x->is_bst & y->is_bst) == false) ok = false;
        
        int curr_val = root->val + x->val + y->val ;
        
        if(ok){
            ans = max(ans, curr_val);
        }
        
        return new Node(
            max(root->val, y->mx), min(root->val, x->mn), curr_val, ok
        );
        
    }
    
    int maxSumBST(TreeNode* root) {
        traverse(root) ;
        return ans ;
    }
};
