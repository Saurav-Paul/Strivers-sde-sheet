// https://leetcode.com/problems/4sum/
class Solution {
    
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        int n = nums.size() ;
        vector<vector<int> > res;
        
        sort(nums.begin(), nums.end()) ;
        
        for(int a = 0; a < n ; a++){
            for(int b = a + 1 ; b < n ; b++){
                long long baki = (long long)target - (long long)nums[a] - (long long)nums[b] ;
                
                int c = b + 1;
                int d = n - 1;
                
                while(c < d){
                    if(nums[c] + nums[d] > baki) d--;
                    else if(nums[c] + nums[d] < baki) c++;
                    else{
                        vector<int> ans ;
                        ans.push_back(nums[a]) ;
                        ans.push_back(nums[b]) ;
                        ans.push_back(nums[c]) ;
                        ans.push_back(nums[d]) ;
                        res.push_back(ans) ;                        
                        
                        // skipping duplicates of num3
                        int _val = nums[c] ;
                        while(c < n && nums[c] == _val) c++;
                        
                        // skipping duplicates of num4
                        _val = nums[d] ;
                        while(d > c && nums[d] == _val) d--;
                    }
                }
                
                // skipping the duplicates of num2
                while(b + 1 < n && nums[b] == nums[b+1]) b++;
            }
            
            // skipping the duplicates of num1
            while(a + 1 < n && nums[a] == nums[a + 1]) a++;
        }

        return res;
    }
};
