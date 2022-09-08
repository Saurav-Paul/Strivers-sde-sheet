//https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
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
    unordered_set <int> _set ;
    bool findTarget(TreeNode* root, int k) {
        if(root == NULL) return false ;
        
        int need = k - root->val ;
        
        if(_set.find(need) != _set.end()) return true ;
        _set.insert(root->val) ;
        
        return ( findTarget(root->left,k) | findTarget(root->right,k) ) ;
    }
};
