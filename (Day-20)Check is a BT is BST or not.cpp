//https://leetcode.com/problems/validate-binary-search-tree/
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

    struct Node{
        long long mn = 1e10;
        long long mx = -1e10;
        bool ok = true ;
        
        Node(long long _min = 1e10, long long _max = -1e10, bool _ok = true){
            mn = _min;
            mx = _max;
            ok = _ok ;
        }
        
        void print(){
            cout << mn << " " << mx << " " << ok << endl;
        }
    };
    
    public:
    Node* traverse(TreeNode* root){
        if(root == NULL){
            return new Node() ;
        }
        
        bool isOk = true;
        
        Node* leftNode = traverse(root->left) ;
        Node* rightNode = traverse(root->right) ;
        
        if(leftNode->mx >= root->val){
            isOk = false;
        }
        
        if(rightNode->mn <= root->val){
            isOk = false;
        }
        
        long long mn = min(rightNode->mn,leftNode->mn);
        long long int mx = max(rightNode->mx, leftNode->mx);
        
        return new Node(
             min((long long)root->val,mn), max((long long)root->val,mx), (isOk & leftNode->ok) & rightNode->ok
        );
    }
    bool isValidBST(TreeNode* root) {
        Node* node = traverse(root) ;
        return node->ok;
    }
};
