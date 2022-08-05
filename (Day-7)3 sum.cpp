//https://leetcode.com/problems/3sum/
class Solution {
public:
    
    int bin_search(vector<int> &nums, int low, int high, int target){
        while(low <= high){
            int mid = (low + high) / 2;
            if(nums[mid] == target){
                return mid ;
            }
            else if(nums[mid] < target){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return -1 ;
    }
    
    vector<vector<int>> threeSum(vector<int>& nums) {
    
        vector<vector<int>> res ;
        sort(nums.begin(), nums.end()) ;
        
        int n = nums.size() ;
        
        for(int i = 0 ; i < n - 2; i++){
            
            if((i == 0) or (i> 0 && nums[i] != nums[i-1])){
                
                
                int st = i + 1, sp = n - 1;
                int have_to_get = 0 - nums[i] ;
                
                while(st < sp){
                    if(nums[st] + nums[sp] == have_to_get){
                        vector<int> v;
                        v.push_back(nums[i]);
                        v.push_back(nums[st]);
                        v.push_back(nums[sp]);
                        res.push_back(v);
                        
                        while(st < sp && nums[st] == nums[st+1]) st ++;
                        while(st < sp && nums[sp] == nums[sp-1]) sp--;
                        
                        st ++ , sp--;
                        
                    }
                    else if(nums[st] + nums[sp] < have_to_get) st ++ ;
                    else sp--;
                    
                }
                
            }

        }
        
        return res ;
    }
};
