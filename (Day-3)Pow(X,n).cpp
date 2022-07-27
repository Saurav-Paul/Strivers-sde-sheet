//https://leetcode.com/problems/powx-n/submissions/
class Solution {
public:
    double myPow(double x, int n) {
        double _p = 1;
        
        long long int _n = n ;
        
        if(_n < 0) _n *= -1 ;
        
        while(_n > 0){
            if(_n % 2 == 0){
                x *= x;
                _n /= 2;
            }
            else{
                _p *= x;
                _n -- ;
            }
        }
        
        if(n < 0) _p = (double)1 / _p;
        
        return _p ;
    }
};
