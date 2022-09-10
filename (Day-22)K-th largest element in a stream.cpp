//https://leetcode.com/problems/kth-largest-element-in-a-stream/
class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq ;
    int _k;
    KthLargest(int k, vector<int>& nums) {
        pq = priority_queue<int, vector<int>, greater<int>>(nums.begin(), nums.end()) ;
        _k = k ;
    }
    
    int add(int val) {
        pq.push(val) ;
        
        while(pq.size() > _k) pq.pop();
        
        return pq.top() ;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
