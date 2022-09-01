//https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
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
    map<int,int> mp;
public:
    
    TreeNode* buildNode(int value){
        TreeNode* node = new TreeNode(value) ;
        return node ;
    }
    
    TreeNode* traverse(
        vector<int> &preorder,
        int pst,
        int pen,
        vector<int> &inorder,
        int ist,
        int ien
    ){
        if(pst > pen || ist > ien) return NULL ;
        
        
        int curr = preorder[pst] ;
        TreeNode* node = buildNode(curr) ;
        
        int curr_pos = mp[curr] ;
        int number_of_element = curr_pos - ist;
        
        node->left = traverse(preorder,pst + 1, pst + number_of_element, inorder, ist, curr_pos - 1);
        node->right = traverse(preorder,pst + number_of_element + 1, pen, inorder, curr_pos + 1, ien) ;
        
        return node;
        
        
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size() ;
        for(int i = 0 ; i < n ; i++){
            mp[inorder[i]] = i ;
        }
        
        int pst = 0, pen = n - 1;
        int ist = 0, ien = n - 1;
        
        return traverse(preorder, pst, pen, inorder, ist, ien) ;
        
    }
};
