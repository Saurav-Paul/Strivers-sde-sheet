//https://leetcode.com/problems/binary-tree-level-order-traversal/
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
    map<int, vector<int> > mp;
    
    void traverse(TreeNode* node, int level){
        if(node == NULL) return ;
        mp[level].push_back(node->val) ;
        traverse(node->left, level+1) ;
        traverse(node->right, level+1) ;
    }
    
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector< vector<int> > res ;
        traverse(root,0) ;
        for(auto x : mp){
            res.push_back(x.second) ;
        }
        return res ;
        
    }
};
