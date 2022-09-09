//https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
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
    TreeNode* traverse(TreeNode *root){
        if(root == NULL) return NULL ;
        
        TreeNode* lft = root->left;
        TreeNode* rght = root->right ;

        
        if(lft != NULL){
            TreeNode *temp = traverse(lft) ;
            root->left = NULL;
            root->right = lft ;
            root = temp ;
        }
        
        if(rght != NULL){
            TreeNode* temp = traverse(rght) ;
            root->right = rght;
            root = temp;
        }
        
        return root ;
    }
    
    void flatten(TreeNode* root) {
        traverse(root) ;
    }
};
