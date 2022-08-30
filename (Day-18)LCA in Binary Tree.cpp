//https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    bool ok = false;
    TreeNode* ans;
    int traverse(TreeNode *node, TreeNode* p, TreeNode* q){
        if(node == NULL) return 0;
        int curr = 0 ;
        if(node == p){
            curr += 1;
        }
        else if(node == q){
            curr += 2 ;
        }
        
        int x = traverse(node->left,p ,q) ;
        int y = traverse(node->right,p ,q) ;
        
        if(ok == false && x + y + curr == 3){
            ans = node ;
            ok = true ;
        }
        
        return curr + x + y ;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        traverse(root,p,q) ;
        return ans ;
    }
};
