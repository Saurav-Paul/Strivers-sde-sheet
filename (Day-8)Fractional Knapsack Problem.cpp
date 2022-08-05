//https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        sort(arr, arr+n , [](Item &a, Item &b){
            double x = (double)a.value / a.weight ;
            double y = (double)b.value / b.weight ;
            return x > y ;
        });
        
        double maximum_value = 0 ;
        for(int i = 0 ; i < n && W > 0 ; i++){
            int mn = min(W,arr[i].weight) ;
            double each = (double) arr[i].value / arr[i].weight ;
            maximum_value += mn * each;
            W -= mn ;
        }
        
        return maximum_value ;
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends
