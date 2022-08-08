//https://leetcode.com/problems/single-element-in-a-sorted-array/submissions/
class Solution {
public:
    
    int getIndex(int num){
        if(num % 2 == 0) return num + 1;
        return num -1 ;
    }
    
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0 , high = nums.size() - 1;
        
        while(low < high){
            int mid = (low + high) / 2 ;
            if(nums[mid] == nums[getIndex(mid)]) low = mid + 1;
            else high = mid;
        }
        
        return nums[low] ;
    }
};
