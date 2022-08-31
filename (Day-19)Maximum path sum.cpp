//https://leetcode.com/problems/binary-tree-maximum-path-sum/
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
    long long mx = INT_MIN ;
    
    long long traverse(TreeNode* node){
        if(node == NULL) return INT_MIN ;
        
        long long x = traverse(node->left) ;
        long long y = traverse(node->right) ;
        
        vector<long long> v = {node->val,x+node->val,y+node->val,x+y+node->val,mx} ;

        for(auto xx : v) mx = max(mx,xx);
        
        x = max(x,0LL) ;
        
        return max({x,y}) + node->val ;
    }
    
    int maxPathSum(TreeNode* root) {
        traverse(root) ;
        return mx;
    }
};
