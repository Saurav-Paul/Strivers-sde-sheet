//https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
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
    void traverse(TreeNode* root, int col,int row){
        if(root == NULL) return ;

        mp[col].push_back({row,root->val}) ;
        
        traverse(root->left,col-1, row + 1) ;
        
        traverse(root->right,col+1, row + 1) ;

    }
public:
    map<int, vector<pair<int,int>>> mp;
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        traverse(root,0,0) ;
        vector<vector<int>> res ;
        for(auto x : mp){
            vector<pair<int,int>> v = x.second ;
            sort(v.begin() , v.end(),[&](pair<int,int> &a, pair<int,int> &b){
                if(a.first == b.first){
                    return a.second < b.second ;
                }
                return a.first < b.first ;
            }) ;
            
            vector<int> temp ;
            for(auto y : v){
                temp.push_back(y.second) ;
            }
            
            res.push_back(temp) ;
        }
        return res ;
    }
};
