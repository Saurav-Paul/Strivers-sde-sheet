//https://leetcode.com/problems/partition-equal-subset-sum/
class Solution {
public:
    
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto x : nums){
            sum += x;
        }
        
        if(sum % 2 == 1) return false;
        
        vector<bool> dp(sum + 1, false) ;
        dp[0] = true;
        
        for(auto num : nums){
            for(int i = sum ; i >= num ; i--){
                if(dp[i - num]){
                    dp[i] = true;
                }
            }
        }
        
        return dp[sum/2] ;
    }
};
