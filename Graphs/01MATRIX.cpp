class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<pair<int,int>,int>> q;
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> ans(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                }
            }
        }
        while(!q.empty())
        {
            int x=q.front().first.first;
            int y=q.front().first.second;
            int dist=q.front().second;
            q.pop();
            int row[]={-1,0,1,0};
            int col[]={0,-1,0,1};
            for(int i=0;i<4;i++)
            {
                int xaxis=x+row[i],yaxis=y+col[i];
                if(xaxis<n && xaxis>=0 && yaxis>=0 && yaxis<m && mat[xaxis][yaxis]==1 && 
                !ans[xaxis][yaxis])
                {
                    q.push({{xaxis,yaxis},dist+1});
                    ans[xaxis][yaxis]=dist+1;
                }
            }
        }
        return ans;
    }
};
