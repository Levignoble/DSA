class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int inicolor = image[sr][sc];
        if (inicolor == color) return image;
        
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        dfs(sr, sc, image, color, delrow, delcol, inicolor);
        return image;
    }

    void dfs(int row, int col, vector<vector<int>>& image, int color, int delrow[], int delcol[], int inicolor) {
        image[row][col] = color;
        int n = image.size();
        int m = image[0].size();

        for (int i = 0; i < 4; i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && image[nrow][ncol] == inicolor) {
                dfs(nrow, ncol, image, color, delrow, delcol, inicolor);
            }
        }
    }
};
