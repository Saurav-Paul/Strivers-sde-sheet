//https://leetcode.com/problems/pascals-triangle/
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> v(0,vector<int>());
        for(int i = 1 ; i <= numRows ; i++){
            vector<int> x;
            x.push_back(1);
            
            for(int j = 0 ; j < i - 2 ; j ++){
                x.push_back(v[i-2][j] + v[i-2][j+1]) ;
            }
            
            if(i > 1)
            x.push_back(1);
            v.push_back(x) ;
        }
        return v;
    }
};
