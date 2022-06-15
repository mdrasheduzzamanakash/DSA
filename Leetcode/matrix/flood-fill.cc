// author: shiponcs
// https://leetcode.com/problems/flood-fill/
class Solution {
public:
    int vis[51][51];
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if( vis[sr][sc] ) return image;
        vis[sr][sc] = 1;
        int cur_color = image[sr][sc];
        image[sr][sc] = newColor;
       
        if( sc + 1 < image[0].size() && cur_color == image[sr][sc + 1] ) {
            image = floodFill(image, sr, sc + 1, newColor);
        }
        if( sc - 1 > -1 && cur_color == image[sr][sc - 1] ) {
            image = floodFill(image, sr, sc - 1, newColor);
        }
        
        if( sr + 1 < image.size() && cur_color == image[sr + 1][sc] ) {
            image = floodFill(image, sr + 1, sc, newColor);

        }
        if( sr - 1 > -1 && cur_color == image[sr - 1][sc] ){
            image = floodFill(image, sr - 1, sc, newColor);

        }

        
        return image;
    }
};

/*
1 1 3 3
Two
0 1 3 3
three
0 2 3 3
*/
