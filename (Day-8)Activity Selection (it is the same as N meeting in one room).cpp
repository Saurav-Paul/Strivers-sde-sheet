//https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<pair<int,int>> meetings ;
        for(int i = 0 ; i < n ; i++){
            pair<int,int> p = {start[i],end[i]};
            meetings.push_back(p) ;
        }
        
        sort(meetings.begin(), meetings.end(), [](pair<int,int> &a, pair<int,int> &b){
            if(a.second == b.second){
                return a.first > b.first;
            }
            return a.second < b.second ;
        });
        
        int total_meetings = 0 ;
        int end_time = 0 ;
        
        for(int i = 0 ; i < n ; i++){
            if(meetings[i].first > end_time){
                total_meetings += 1;
                end_time = max(end_time, meetings[i].second) ;
                
            }
        }
        
        return total_meetings;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends
