//https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
    TreeNode* ans = NULL ;
public:
    
    TreeNode* traverse(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == NULL) return NULL ;
        
        int cnt = 0 ;
        TreeNode* temp = NULL ;
        
        if(root == p) {
            cnt ++ ;
            temp = p;
        }
        else if(root == q){
            cnt ++ ;
            temp = q;
        }
        
        TreeNode* x = traverse(root->left, p, q) ;
        TreeNode* y = traverse(root->right, p, q) ;
        
        if(x != NULL){
            cnt ++ ;
            temp = x;
        }
        
        if(y != NULL){
            cnt ++ ;
            temp = y ;
        }
        
        if(cnt == 2 && ans == NULL){
            ans = root ;
        }
        
        return temp ;
        
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        traverse(root,p,q) ;
        return ans ;
    }
}
