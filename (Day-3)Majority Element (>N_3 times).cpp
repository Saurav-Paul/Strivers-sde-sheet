//https://leetcode.com/problems/majority-element-ii/submissions/
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n1 = -1 , n2 = -1 , c1 = 0 , c2 = 0;
        
        for(auto num : nums){
            if(n1 == num) c1 ++ ;
            else if(n2 == num) c2 ++ ;
            else if(c1 == 0) n1 = num, c1 = 1;
            else if(c2 == 0) n2 = num , c2 = 1;
            else c1--, c2-- ;
        }
        
        c1 = 0, c2 = 0;
        
        for(auto num : nums){
            if(num == n1) c1 ++;
            else if(num == n2) c2 ++;
        }
        
        int n_3 = nums.size() / 3 ;
        
        vector<int> ans ;
        
        if(n_3 < c1) ans.push_back(n1);
        if(n_3 < c2) ans.push_back(n2);
        
        return ans ;
    }
};
