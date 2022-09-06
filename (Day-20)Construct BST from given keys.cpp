//https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return traverse(nums,0,nums.size() - 1) ;
    }
    
    TreeNode* traverse(vector<int> &nums, int st, int en){
        if(st > en) return NULL ;
        
        int middlePoint = st + (en - st) / 2 ;
        
        TreeNode *node = new TreeNode(nums[middlePoint]) ;
        
        node->left = traverse(nums,st,middlePoint-1);
        node->right = traverse(nums,middlePoint+1, en) ;
        
        return node ;
        
    }
};
