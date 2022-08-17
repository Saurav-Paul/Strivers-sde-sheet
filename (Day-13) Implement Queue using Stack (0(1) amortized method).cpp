//https://leetcode.com/problems/implement-queue-using-stacks/
class MyQueue {
    stack<int> a, b;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        a.push(x) ;
    }
    
    void transfer(){
        while(a.size()){
            b.push(a.top()) ;
            a.pop() ;
        }
    }
    
    int getElement(bool remove = false){
        if(b.size() == 0){
            transfer() ;
        }
        int res = b.top();
        if(remove) b.pop() ;
        return res;
    }
    
    int pop() {
        return getElement(true) ;
    }
    
    int peek() {
        return getElement() ;
    }
    
    bool empty() {
        return (a.size() + b.size() == 0) ;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
