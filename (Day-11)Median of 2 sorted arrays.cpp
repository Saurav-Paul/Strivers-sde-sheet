//https://leetcode.com/problems/median-of-two-sorted-arrays/
class Solution {
public:
    
    double findMedian(vector<int>&v1, vector<int> &v2){
        int low = 0, high = v1.size();
        int medianPos = (v1.size() + v2.size() + 1) / 2 ;
        
        while(low <= high){
            int cut1 = (low + high) >> 1;
            int cut2 = medianPos - cut1;
            
            int l1 = (cut1 == 0 ? INT_MIN : v1[cut1-1]);
            int l2 = (cut2 == 0 ? INT_MIN : v2[cut2-1]);
            int r1 = (cut1 == v1.size() ? INT_MAX : v1[cut1]);
            int r2 = (cut2 == v2.size() ? INT_MAX : v2[cut2]);
            
            if(l1 <= r2 && l2 <= r1){
                if( (v1.size() + v2.size()) % 2 ==0 ){
                    return (max(l1,l2) + min(r1,r2) )/ 2.0 ;
                }
                else{
                    return max(l1,l2) ;
                }
            }
            else if(l1 > r2) high = cut1 - 1;
            else low = cut1 + 1;
        }
        
        return 0.0;
    }
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        
        if(n > m){
            return findMedian(nums2,nums1) ;
        }
        else{
            return findMedian(nums1,nums2) ;
        }
    }
};
