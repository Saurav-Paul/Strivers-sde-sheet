//https://leetcode.com/problems/next-permutation/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        
        for(auto x : nums){
            cout << x << " " ;
        }
        cout<< endl ;
        
        int st , sp ;
        st = 0 ;
        sp = nums.size() - 1;
        
        for(int i = nums.size() - 1 ; i > 0 ; i--){
            if(nums[i] > nums[i-1]){
                st = i - 1 ;
                break ;
            }
        }
        
        for(int i = nums.size() -1 ; i > 0 ; i--){
            if(nums[st] < nums[i]){
                sp = i ;
                break;
            }
        }
        
        swap(nums[st], nums[sp]);
        
        for(int i = st + 1 ; i < nums.size() ; i ++){
            for(int j = i + 1 ; j < nums.size() ; j ++){
                if(nums[i] > nums[j]) swap(nums[i], nums[j]);
            }
        }

        

    }
};
