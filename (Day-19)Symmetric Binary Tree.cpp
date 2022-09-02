//https://leetcode.com/problems/symmetric-tree/
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
    
    int mxRow = 0 ;
    
    void traverse(TreeNode* node, int row, map<int,vector<int>> &mp){
        if(node == NULL){
            mp[row].push_back(-1000) ;
            return ;
        }
        
        mxRow = max(row, mxRow) ;
        
        mp[row].push_back(node->val) ;
        traverse(node->left,row+1,mp) ;
        traverse(node->right,row+1,mp) ;

        
    }
public:
    bool isSymmetric(TreeNode* root) {
        map<int,vector<int>> lmp, rmp;
        traverse(root->left,0,lmp) ;
        traverse(root->right,0,rmp) ;
        
        for(int i = 0 ; i <= mxRow ; i++){
            vector<int> x = lmp[i] ;
            vector<int> y = rmp[i] ;
            
            reverse(y.begin(), y.end()) ;
            
            if(x != y) return false;
        }
        
        return true;
    }
};
