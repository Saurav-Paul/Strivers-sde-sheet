//https://leetcode.com/problems/implement-stack-using-queues/submissions/
class MyStack {
    
    queue<int> a, b;
    
public:
    MyStack() {
        
    }
    
    void push(int x) {
        a.push(x) ;
    }
    
    int pop() {
        int n = a.size() - 1;
        while(n--){
            int t = a.front();
            a.pop();
            a.push(t) ;
        }
        int ans =  a.front();
        a.pop() ;
        return ans ;
    }
    
    int top() {
        int n = a.size() - 1;
        while(n--){
            int t = a.front();
            a.pop();
            a.push(t) ;
        }
        int ans =  a.front();

        a.pop();
        a.push(ans) ;

        return ans ;
    }
    
    bool empty() {
        return (a.size() == 0);
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
