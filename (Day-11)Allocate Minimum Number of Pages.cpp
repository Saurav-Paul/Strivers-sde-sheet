//https://www.interviewbit.com/problems/allocate-books/discussion/p/easy-binary-search-solution-easy/321300/901
int Solution::books(vector<int> &A, int B) {
    
    int sum = 0 ;
    int mx = 0 ;
    int n = A.size() ;
    
    if(n < B) return -1;
    
    for(int i = 0 ; i < n ; i++){
        sum += A[i] ;
        mx = max(mx, A[i]);
    }
    
    int low = mx, high = sum, ans = -1 ;
    
    while(low <= high){
        int mid = (low + high) / 2;
        bool possible = true;
        
        // checking if possible
        int student = 1, pages = 0;
        for(int i = 0 ; i < n ; i++){
            pages += A[i];

            if(pages > mid){
                ++ student;
                pages = A[i] ;
            }
        }
        if(student <= B){
            ans = mid ;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    
    return ans;
}
