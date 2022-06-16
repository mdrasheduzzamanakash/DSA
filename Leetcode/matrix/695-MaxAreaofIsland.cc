// author: abdul matin
// problem link: https://leetcode.com/problems/max-area-of-island/

class Solution {
public:
    bool vis[51][51];
    int row;
    int col;
    void calArea(vector< vector< int > >& grid, int i, int j, int& cnt) {
        if( vis[i][j] ) return;
        vis[i][j] = 1, cnt++;
        if( i - 1 > -1 && grid[i - 1][j] )  calArea(grid, i - 1, j, cnt);
        if( i + 1 < row && grid[i + 1][j] ) calArea(grid, i + 1, j, cnt);
        if( j - 1 > -1 && grid[i][j - 1] )  calArea(grid, i, j - 1, cnt);
        if( j + 1 < col && grid[i][j + 1] ) calArea(grid, i, j + 1, cnt);    
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        row = grid.size();
        col = grid[0].size();
        int ans = 0;

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if(grid[i][j] == 1 ){
                    int cnt = 0;
                    calArea( grid, i, j, cnt );
                    ans = max( ans, cnt );
                }
            }
        }
        
        return ans;
    }
};
