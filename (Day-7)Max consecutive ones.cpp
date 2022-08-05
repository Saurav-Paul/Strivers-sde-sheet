//https://leetcode.com/problems/max-consecutive-ones/
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int temp = 0, mx = 0 ;
        
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] == 0){
                mx = max(mx,temp) ;
                temp = 0 ;
            }
            else{
                temp ++ ;
            }
        }
        
        mx = max(mx,temp) ;
        
        return mx ;
    }
};
