class Solution {
public:
void dfs(int u,vector<vector<int>>&adj,vector<bool>&visited)
{
    visited[u]=true;
    for(auto x:adj[u])
    {
        if(!visited[x])dfs(x,adj,visited);
    }
}
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        vector<bool>visited(n,false);
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                count++;
                dfs(i,adj,visited);
            }
        }

    return count;
    }
    // return count;
};
