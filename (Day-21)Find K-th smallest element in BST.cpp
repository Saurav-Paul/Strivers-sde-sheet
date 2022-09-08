//https://leetcode.com/problems/kth-smallest-element-in-a-bst/
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
    int ans = - 1;
    int cnt = 0;
    void traverse(TreeNode* root, int k){
        if(root == NULL) return ;

        traverse(root->left, k) ;
        cnt ++ ;
        if(cnt == k) {
            ans = root->val ;
            return ;            
         };
        traverse(root->right, k) ;
        
        return ;
        
    }
    int kthSmallest(TreeNode* root, int k) {
        traverse(root, k) ;
        return ans ;
    }
};
