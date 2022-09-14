//https://leetcode.com/problems/longest-increasing-subsequence/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp ;
        
        int p = - 1;
        
        for(int i = 0 ;i < nums.size() ; i++){
            if(dp.empty() or dp.back() < nums[i]){
                dp.push_back(nums[i]) ;
            }
            else{
                int lowPos = lower_bound(dp.begin(),dp.end(),nums[i]) - dp.begin();
                dp[lowPos] = nums[i] ;
            }
        }
        
        return dp.size();
    }
};
