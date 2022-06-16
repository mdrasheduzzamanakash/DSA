class Solution {
public:
    int row, col;
    int vis[302][302];
    
    void markVis(vector<vector<char>>& grid, int i, int j) {
        if(vis[i][j]) return;
        vis[i][j] = 1;
        if(i - 1 > -1 && grid[i - 1][j] == '1')     markVis(grid, i - 1, j);
        if(i + 1 < row && grid[i + 1][j] == '1')    markVis(grid, i + 1, j);
        if(j - 1 > -1 && grid[i][j - 1] == '1')      markVis(grid, i, j - 1);
        if(j + 1 < col && grid[i][j + 1] == '1')    markVis(grid, i, j + 1);
    }
    int numIslands(vector<vector<char>>& grid) {
        row = grid.size();
        col = grid[0].size();
        int ans = 0;
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; ++j) {
               if(!vis[i][j] && grid[i][j] == '1') {
                   ++ans;
                   markVis(grid, i, j);
               } 
            }
        }
        return ans;
    }
};
