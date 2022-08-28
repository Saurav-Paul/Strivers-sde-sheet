//https://leetcode.com/problems/binary-tree-postorder-traversal/
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
    void postOrder(TreeNode* node, vector<int> &v){
        if(node == NULL) return ;
        postOrder(node->left,v) ;
        postOrder(node->right,v) ;
        v.push_back(node->val) ;
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> v;
        postOrder(root,v) ;
        return v;
    }
};
