//https://practice.geeksforgeeks.org/problems/subset-sums2234/1
//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    void recursive_sum(vector<int> &arr, int sum , int index, vector<int> &res){
        res.push_back(sum) ;
        for(int i = index + 1 ; i < arr.size() ; i++){
            recursive_sum(arr,sum + arr[i] , i , res) ;
        }
    }

    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int> res ={0};
        
        for(int i = 0 ; i < N ; i++){
            recursive_sum(arr,arr[i],i,res) ;
        }
        
        return res ;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends
