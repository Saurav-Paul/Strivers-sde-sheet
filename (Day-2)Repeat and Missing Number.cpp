//https://www.interviewbit.com/problems/repeat-and-missing-number-array/
vector<int> Solution::repeatedNumber(const vector<int> &A) {
    int n = A.size() ;
    vector<int> cal(n+1,0) ;
    
    vector<int> ans ;
    
    for(auto x : A) cal[x] ++ ;
    
    int a, b ;
    
    for(int i = 1 ; i <= n ; i++){
        if(cal[i] == 0 ) b = i ;
        if(cal[i] > 1) a = i;
    }
    
    ans.push_back(a);
    ans.push_back(b);
    
    return ans;
}
