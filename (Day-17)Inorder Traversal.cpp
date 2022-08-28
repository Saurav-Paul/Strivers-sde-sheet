//https://leetcode.com/problems/binary-tree-inorder-traversal/
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
    
    void inOrder(TreeNode *node, vector<int> &v){
        if(node == NULL) return ;
        inOrder(node->left,v) ;
        v.push_back(node->val) ;
        inOrder(node->right,v) ;
    }
    
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v ;
        inOrder(root, v) ;
        return v ;
    }
};
