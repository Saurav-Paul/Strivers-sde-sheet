//https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        unordered_map<int,int> mp;
        
        int x = 0 ;
        int mx_len = 0 ;
        
        for(int i = 0 ; i < A.size() ; i++){
            
            x += A[i] ;
            
            if(A[i] == 0) mx_len = max(mx_len,1) ;
            
            if(mp.find(x) != mp.end()){
                mx_len = max(mx_len,i - mp[x]);
            }
            else{
                mp[x] = i;
            }
        }
        
        /*
        15 -2 2 -8 1 7 10 23
        15 13 15 7 8 15 25 48
        */
        
        return mx_len ;
    }
};
