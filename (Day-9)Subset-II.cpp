//https://leetcode.com/problems/subsets-ii/
class Solution {
public:
    void solve(vector<int>&nums, int index, vector<int> &v, vector<vector<int>> &res){
        res.push_back(v) ;
        
        for(int i = index ; i < nums.size() ; i++){
            if(i != index &&  nums[i] == nums[i-1]) continue ;
            v.push_back(nums[i]) ;
            solve(nums,i+1,v,res) ;
            v.pop_back() ;
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector< vector<int> > res ;
        sort(nums.begin(), nums.end()) ;
        vector<int> v;
        solve(nums,0,v,res) ;

        return res;
    }
};
