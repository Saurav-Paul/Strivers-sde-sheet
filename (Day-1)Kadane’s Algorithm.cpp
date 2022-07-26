//https://leetcode.com/problems/maximum-subarray/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0] ;
        int sum = nums[0];
        
        for(int i = 1 ; i < nums.size() ; i++){
            sum = max(nums[i], sum + nums[i]) ;
            ans = max(ans, sum) ;
        }
        
        return ans ;
    }
};
