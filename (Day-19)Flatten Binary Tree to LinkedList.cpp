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
    
    TreeNode* prev ;
    void traverse(TreeNode *node){
        if(node == NULL) return ;
        
        TreeNode* leftNode = node->left;
        TreeNode* rightNode = node->right ;
        
        traverse(rightNode) ;
        traverse(leftNode) ;
        node->left = NULL;
        node->right = prev ;
        prev = node;
        
    }
public:
    void flatten(TreeNode* root) {
        traverse(root);
    }
};
