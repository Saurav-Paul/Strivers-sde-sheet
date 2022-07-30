// https://leetcode.com/problems/longest-consecutive-sequence/submissions/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        set<int> _s(nums.begin(), nums.end()) ;
        nums.assign(_s.begin() , _s.end()) ;
        
        int mx = 0, temp=0;
        for(int i = 0; i < nums.size() ; i++){
            if(i == 0) temp = 1;
            else if(nums[i] == nums[i-1] + 1) ++temp;
            else temp = 1;
            
            mx = max(mx,temp) ;
        }
        return mx;
    }
};
