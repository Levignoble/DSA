/*
Time Complexity: O(n * m)
- We traverse each cell of the board once during the DFS, making the overall complexity O(n * m), 
  where n is the number of rows and m is the number of columns.

Space Complexity: O(n * m)
- We use an additional 'vis' array of size n * m to track visited cells.
- In the worst case, the DFS recursion stack can also go as deep as O(n * m), leading to a total space complexity of O(n * m).
*/

class Solution {
public:
    void dfs(int x, int y, vector<vector<int>>& vis, vector<vector<char>>& board, int n, int m) {
        vis[x][y] = 1;
        board[x][y] = 'S';  // Mark the cell as safe (connected to border 'O')
        int row[] = {-1, 0, 1, 0};
        int col[] = {0, -1, 0, 1};
        
        for (int i = 0; i < 4; i++) {
            int r = x + row[i], c = y + col[i];
            if (r >= 0 && r < n && c >= 0 && c < m && board[r][c] == 'O' && !vis[r][c]) {
                dfs(r, c, vis, board, n, m);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));  // Visited array to track explored cells
        
        // Traverse the first and last row for border-connected 'O's
        for (int i = 0; i < m; i++) {
            if (!vis[0][i] && board[0][i] == 'O') dfs(0, i, vis, board, n, m);
            if (!vis[n-1][i] && board[n-1][i] == 'O') dfs(n-1, i, vis, board, n, m);
        }
        
        // Traverse the first and last column for border-connected 'O's
        for (int i = 0; i < n; i++) {
            if (!vis[i][0] && board[i][0] == 'O') dfs(i, 0, vis, board, n, m);
            if (!vis[i][m-1] && board[i][m-1] == 'O') dfs(i, m-1, vis, board, n, m);
        }

        // Flip remaining 'O's to 'X', and revert 'S' back to 'O'
        for (int i = 0; i < n; i++)
