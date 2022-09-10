//https://leetcode.com/problems/flood-fill/
class Solution {
public:
    int n, m ;
    
    void traverse(vector<vector<int>> &image, int sr, int sc, int color){
        int curr = image[sr][sc] ;
        
        if(curr == color) return ;
        
        image[sr][sc] = color ;
        
        // left
        if(sc > 0 && image[sr][sc-1] == curr){
            traverse(image, sr, sc-1, color) ;
        }
        
        // right
        if(sc < m - 1 && image[sr][sc+1] == curr){
            traverse(image, sr, sc+1, color) ;
        }
        
        // up
        if(sr > 0 && image[sr-1][sc] == curr){
            traverse(image, sr-1, sc, color) ;
        }
        
        // down
        if(sr < n-1 && image[sr+1][sc] == curr){
            traverse(image, sr+1, sc, color) ;
        }
        
        
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        n = image.size() ;
        m = image[0].size() ;
        traverse(image,sr,sc,color) ;
        return image;
    }
};
