//https://leetcode.com/problems/diameter-of-binary-tree/
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
    int mx = 0 ;
    
    int traverse(TreeNode* node){
        if(node == NULL) return 0;
        
        int x = traverse(node->left) ;
        int y = traverse(node->right) ;
        
        mx = max(mx, x+y) ;
        
        return max(x, y) + 1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        traverse(root) ;
        return mx;
    }
};
