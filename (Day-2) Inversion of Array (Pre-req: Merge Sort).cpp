// https://www.codingninjas.com/codestudio/problems/count-inversions_615
#include <bits/stdc++.h> 

long long int merge(vector<long long int> &arr, vector<long long int> &temp, int st, int mid, int sp){
    int i = st;
    int j = mid;
    int k = st;
    
    long long int cnt = 0;
    
    while((i <= mid - 1) && (j <= sp)){
        if(arr[i] <= arr[j]){
            temp[k++] = arr[i++];
        }
        else{
            temp[k++] = arr[j++];
            cnt = cnt + (mid-i);
        }
    }
    
    while(i <= mid - 1){
        temp[k++] = arr[i++] ;
    }
    
    while(j <= sp){
        temp[k++] = arr[j++] ;
    }
    
    for(int i = st ; i <= sp ; i++) arr[i] = temp[i] ;

    return cnt ;
}

long long int merge_sort(vector<long long int> &arr, vector<long long int> &temp,int st,int sp){
    long long int cnt = 0 ;
    
    if(sp > st){
        int mid = (st + sp) / 2;
        cnt += merge_sort(arr, temp, st, mid) ;
        cnt += merge_sort(arr, temp, mid+1 , sp) ;
        
        cnt += merge(arr, temp,st, mid+1, sp ) ;
    }
    
    return cnt;
}

long long getInversions(long long *arr, int n){
    long long int temp[n] ;
    
    vector<long long int> v, t;
    
    for(int i = 0 ; i < n ;i++){
        v.push_back(arr[i]) ;
        t.push_back(0) ;
    }
    
    return merge_sort(v, t,0, n-1) ;
    // Write your code here.
}
