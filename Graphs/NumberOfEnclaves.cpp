class Solution {
public:
    void dfs(int x, int y, vector<vector<int>>& vis, vector<vector<int>>& grid, int delrow[], int delcol[]){
        vis[x][y] = 1;
        int n = grid.size(), m = grid[0].size();

        for(int i = 0; i<4; i++){
            int newx = x+delrow[i];
            int newy = y+delcol[i];
            if(newx>=0 && newx<n && newy>=0 && newy<m && !vis[newx][newy] && grid[newx][newy] == 1){
                dfs(newx, newy, vis, grid, delrow, delcol);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        int delrow[] = {-1, 0, +1, 0};
        int delcol[] = {0, +1, 0, -1};

        for(int j = 0; j<m; j++){
            if(!vis[0][j] && grid[0][j] == 1){
                dfs(0, j, vis, grid, delrow, delcol);
            }
            if(!vis[n-1][j] && grid[n-1][j] == 1){
                dfs(n-1, j, vis, grid, delrow, delcol);
            }
        }
        for(int i = 0; i<n; i++){
            if(!vis[i][0] && grid[i][0] == 1){
                dfs(i, 0, vis, grid, delrow, delcol);
            }
            if(!vis[i][m-1] && grid[i][m-1]){
                dfs(i, m-1, vis, grid, delrow, delcol);
            }
        }

        int count = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    count++;
                }
            }
        }
        return count;
    }
};
