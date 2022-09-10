//https://leetcode.com/problems/kth-largest-element-in-an-array/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        priority_queue<int> pq;
        
        for(auto x : nums) pq.push(x) ;
        
        int n =  k - 1;
        
        while(n--) pq.pop();
        
        return pq.top();
        
    }
};
