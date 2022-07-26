//https://leetcode.com/problems/merge-sorted-array/
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {       
        
        for(int i = m -1 ; i >= 0 ; i --){
            nums1[i+n] = nums1[i] ;
        }
        
        for(int i = 0 ; i < n ; i++) nums1[i] = 0;
        
        int x = n, y = 0, mi = 0;
        
        while(mi < n + m){
            if(x < m + n && y < n){
                if(nums1[x] < nums2[y]){
                    nums1[mi++] = nums1[x++] ;
                }
                else{
                    nums1[mi++] = nums2[y++];
                }
            }
            else if(x < n + m){
                nums1[mi++] = nums1[x++] ;
            }
            else if(y < n){
                nums1[mi++] = nums2[y++];
            } else{
                break;
            }
        }
        
        
    }
};
