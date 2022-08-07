//https://leetcode.com/problems/permutations/
class Solution {
public:
    void permutations_using_recursion(vector<int> &nums, vector<int> v,vector<int> &freq, vector<vector<int>> &res){
        if(v.size() == nums.size()){
            res.push_back(v) ;
            return ;
        }
        for(int i = 0 ; i < nums.size() ; i++){
            if(freq[i] == 0){
                freq[i] = 1;
                v.push_back(nums[i]) ;
                permutations_using_recursion(nums,v,freq,res) ;
                v.pop_back();
                freq[i] = 0 ;
            }
        }
    }
    
    void permutation_with_backtracking(vector<int> &nums, int index, vector<vector<int>> &res){
        if(index == nums.size()){
            res.push_back(nums) ;
            return ;
        }
        
        for(int i = index ; i < nums.size() ; i++){
            swap(nums[i], nums[index]) ;
            permutation_with_backtracking(nums,index + 1, res) ;
            swap(nums[i], nums[index]) ;
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        permutation_with_backtracking(nums,0,res) ;
        return res;
    }
};
