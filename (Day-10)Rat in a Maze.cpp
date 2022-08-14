//https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1
//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    
    map<char, pair<int,int>> direction;
    
    void solve(int x, int y,vector<vector<int>> &m, vector<vector<int>> &isVisited, int n,string s, set<string> &res){
        
        // base cases
        for(auto node : {x,y}){
            if(node < 0 || node >= n) return;
        }
        
        if(m[x][y] == 0) return ;
        
        if(x == n-1 && y == n-1){
            res.insert(s);
            return ;
        }
        m[x][y] = 0;
        for(auto d: "DLRU"){
            pair<int,int> p = direction[d] ;
            solve(x + p.first, y + p.second, m, isVisited, n, s + d, res) ;
        }
        m[x][y] = 1;
        
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        
        direction['D'] = {1,0};
        direction['L'] = {0,-1};
        direction['R'] = {0,1};
        direction['U'] = {-1,0};
        
        vector<vector<int>> isVisited(n,vector<int>(n,0)) ;
        set<string> res;
        solve(0,0,m,isVisited,n,"",res) ;
        vector<string> ans;
        ans.assign(res.begin(), res.end());
        return ans ;
    }
};

    
//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
