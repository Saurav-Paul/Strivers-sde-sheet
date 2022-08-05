//https://leetcode.com/problems/remove-duplicates-from-sorted-array/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int pointer = 0 ;
        
        for(int i = 0 ; i < nums.size() ; i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            nums[pointer++] = nums[i] ;
        }
        
        return pointer ;
    }
};
