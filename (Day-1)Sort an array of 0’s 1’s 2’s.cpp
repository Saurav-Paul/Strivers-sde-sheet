//https://leetcode.com/problems/sort-colors/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> v(400, 0) ;
        
        
        for(int i = 0 ; i < nums.size() ; i++){
            v[nums[i]] ++ ;
        }
        
        int x = 0 ;
        
        for(int t = 0 ; t < v.size() ; t ++){
            
            for(int i = 0 ; i < v[t] ; i ++){
                nums[x] = t ;
                ++ x;
            }
        }

        
    }
};
