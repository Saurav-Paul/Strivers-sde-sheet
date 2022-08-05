//https://leetcode.com/problems/trapping-rain-water/
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size() ;
        vector<int> bounderies(n, 0) ;
        int temp = 0 ;
        
        for(int i = 0; i < n ; i++){
            if(height[i] > temp) {
                temp = height[i] ;
                bounderies[i] = 1;
            }
        }
        
        temp = 0 ;
        
        for(int i = n - 1 ; i >= 0 ; i--){
            if(height[i] > temp){
                temp = height[i] ;
                bounderies[i] = 1;
            }
        }
        
        int cnt = 0, sum = 0, block = 0;
        temp = 0 ;
        
        int i = 0 ;
        for(i = 0 ; i < n ; i++){
            if(bounderies[i] == 1){
                temp = height[i] ;
                break;
            }
        }
        
        
        for(; i < n ; i++){
            if(bounderies[i] == 1){
                temp = min(height[i], temp) ;
                int total = cnt * temp ;
                sum += (total - block) ;
                temp = height[i];
                block = 0 ;
                cnt = 0 ;
            }
            else{
                block += height[i] ;
                cnt ++ ;
            }
        }
        
        return sum;
    }
};
