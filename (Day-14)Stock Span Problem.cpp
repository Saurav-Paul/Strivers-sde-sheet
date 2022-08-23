//https://leetcode.com/problems/online-stock-span/
class StockSpanner {
    stack<int> stk;
    unordered_map<int,int> mp;
public:
    StockSpanner() {
        
    }
    
    
    int next(int price) {
        
        if(stk.size() == 0){
            mp[price] = 1 ;
            stk.push(price);
            return 1;
        }
        
        if(stk.top() > price){
            mp[price] = 1;
            stk.push(price) ;
            return 1;
        }
        
        int ans = 0 ;
        while(stk.size() and stk.top() <= price){
            ans += mp[stk.top()] ;
            stk.pop();
        }
        
        stk.push(price) ;
        ans ++ ;
        mp[price] = ans;
        
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
