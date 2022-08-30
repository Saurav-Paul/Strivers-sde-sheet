//https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
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
    map<int, vector<int> > mp;
    void traverse(TreeNode* node, int depth){
        if(node == NULL) return ;
        mp[depth].push_back(node->val) ;
        traverse(node->left, depth+1) ;
        traverse(node->right, depth+1) ;
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector< vector<int> > res ;
        
        traverse(root,0) ;
        
        bool reverse_it = false ;
        for(auto x: mp){
            vector<int> temp = x.second ;
            if(reverse_it)
                reverse(temp.begin(),temp.end()) ;
            res.push_back(temp) ;
            reverse_it = !reverse_it;
        }
        return res;
    }
};
