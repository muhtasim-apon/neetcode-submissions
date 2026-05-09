class Solution {
public:
void isvalid(int u,vector<vector<int>>&adj,vector<bool>&visited,int &edge,vector<int>&parent,int n,bool &test)
{
    visited[u]=true;
    for(auto x:adj[u])
    {
        if(!visited[x])
        {
            parent[x]=u;
           // edge++;
            //if(edge>n-1)return false;
            isvalid(x,adj,visited,edge,parent,n,test);
        }
        else if (x!=parent[u])
        test=true;
    }
    //return true;
}
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        vector<bool>visited(n,false);
        //map<int,int>parent;
        vector<int>parent(n,-1);
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        //parent[0]=-1;
        bool test=false;
        int count=0,edge=0;
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
               // parent[i]=-1;
                count++;
                isvalid(i,adj,visited,edge,parent,n,test);
            }
        }
       // cout<<count<<"\n";
        if(count>1 || test)return false;
        return true;
    }
};
