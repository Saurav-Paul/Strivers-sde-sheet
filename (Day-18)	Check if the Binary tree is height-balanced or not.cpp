//https://leetcode.com/problems/balanced-binary-tree/submissions/
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
    bool ok = true ;
    int traverse(TreeNode* node){
        if(node == NULL) return 0;
        int x = traverse(node->left) ;
        int y = traverse(node->right) ;
        
        if(abs(x-y) > 1){
            ok = false;
        }
        
        return max(x,y) + 1;
    }
    bool isBalanced(TreeNode* root) {
        traverse(root) ;
        return ok;
    }
};
