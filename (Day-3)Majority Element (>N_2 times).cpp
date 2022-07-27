//https://leetcode.com/problems/majority-element/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0 ;
        int ans = 0 ;
        
        for(auto num : nums){
            if(cnt == 0) ans = num ;
            
            if(num == ans) cnt ++ ;
            else cnt -- ;
            
        }
        
        return ans ;
    }
};
