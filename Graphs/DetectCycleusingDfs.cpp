// TIME: O(N+2E)+O(N)
   SPACE: O(N)+O(N)


class Solution {
  public:
    bool detect(vector<int> adj[],int src,vector<int> vis)
    {
        vis[src]=1;
        queue<pair<int,int>> q;
        q.push({src,-1});
        while(!q.empty()){
            int node=q.front().first;
            int parent=q.front().second;
            q.pop();
            for(auto it:adj[node]){
                if(vis[it]==0){
                    q.push({it,node});
                    vis[it]=1;
                }
                else if(it!=parent) return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> vis(V,0);
        for(int i=0;i<V;i++)
        {
            if(vis[i]==0)
            {
                if(detect(adj,i,vis)==true) return true;
            }
        }
        return false;
    }
};
