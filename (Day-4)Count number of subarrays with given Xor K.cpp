//https://www.interviewbit.com/problems/subarray-with-given-xor/
int Solution::solve(vector<int> &A, int B) {
    unordered_map<int,int> mp;
    int sum = 0 ;
    int _xor = 0 ;
    mp[_xor] = 1;
    
    for(int i = 0 ; i < A.size() ; i++){
        _xor ^= A[i] ;
        int temp = _xor ^ B;
        
        if(mp.find(temp) != mp.end()){
            sum += mp[temp] ;
        }
        mp[_xor]++;

    }
    
    return sum;
}
