//https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/
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
    void traverse(TreeNode *node, int val){
        int curr = node->val ;
        
        if(val < curr){
            if(node->left != NULL){
                traverse(node->left, val) ;
            }
            else{
                TreeNode* temp = new TreeNode(val) ;
                node->left = temp ;
            }
        }
        else{
            if(node->right != NULL){
                traverse(node->right, val) ;
            }
            else{
                TreeNode* temp = new TreeNode(val) ;
                node->right = temp ;
            }
        }
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        int n = preorder.size() ;
        TreeNode* head = new TreeNode(preorder[0]);
        
        for(int i = 1 ; i < n ; i++){
            traverse(head, preorder[i]) ;
        }
        
        return head ;
    }
};
