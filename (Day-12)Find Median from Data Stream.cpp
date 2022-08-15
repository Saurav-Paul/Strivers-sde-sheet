//https://leetcode.com/problems/find-median-from-data-stream/submissions/
class MedianFinder {

    priority_queue<int> mx_heap;
    priority_queue<int,vector<int>,greater<int>> mn_heap;
    
    public:
    
    MedianFinder() {
        // no need this section
    }
    
    void addNum(int num) {
        if(mx_heap.size() == 0){
            mx_heap.push(num);
            return ;
        }
        
        if(num > mx_heap.top()){
            mn_heap.push(num);
        }
        else{
            mx_heap.push(num);
        }
        
        if(mx_heap.size() > mn_heap.size()){
            int top = mx_heap.top();
            mx_heap.pop();
            mn_heap.push(top);
        }
        
        if(mn_heap.size() -1 > mx_heap.size()){
            mx_heap.push(mn_heap.top()) ;
            mn_heap.pop();
        }
        
    }
    
    
    double findMedian() {
        int mx = mx_heap.size(), mn = mn_heap.size() ;
        if(mx + mn == 0) return 0;
        if(mx == mn){
            int sum = mn_heap.top() + mx_heap.top() ;
            return (double) sum/2;
        }
        else{
            if(mx + mn == 1) return mx_heap.top();
            return mn_heap.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
