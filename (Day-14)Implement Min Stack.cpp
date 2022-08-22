//https://leetcode.com/problems/min-stack/
class MinStack {
    stack<pair<int,int>> stk;
public:
    MinStack() {
    }
    
    void push(int val) {
        if(stk.empty()){
            stk.push({val,val});
        }
        else{
            auto top = stk.top().second;
            stk.push({val, min(top,val)}) ;
        }
    }
    
    void pop() {
        stk.pop() ;
    }
    
    int top() {
        auto top = stk.top();
        return top.first;
    }
    
    int getMin() {
        auto top = stk.top();
        return top.second ;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
