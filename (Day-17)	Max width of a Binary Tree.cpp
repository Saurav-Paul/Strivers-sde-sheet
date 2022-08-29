//https://leetcode.com/problems/maximum-width-of-binary-tree/
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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0 ;
        long long ans = 0 ;
        
        queue<pair<TreeNode*, long long> > q;
        q.push({root,0}) ;
        
        while(!q.empty()){
            long long mn = q.front().second;
            int sz = q.size() ;
            long long first, last ;
            
            for(int i = 0 ; i < sz ; i++){
                long long curr = q.front().second - mn ;
                TreeNode* temp = q.front().first ;
                q.pop();
                if(i == 0) first = curr;
                if(i == sz - 1) last = curr ;
                
                if(temp->left) q.push({temp->left, 2 * curr + 1});
                if(temp->right) q.push({temp->right, 2 * curr + 2}) ;
            }
            
            ans = max(ans, last - first + 1) ;
        }
        
        return ans ;
    }
};
