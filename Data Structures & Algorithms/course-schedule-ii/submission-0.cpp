class Solution {
public:
void isdag(int u,vector<vector<int>>&adj,vector<bool>&visited,vector<bool>&inprocess,bool &test,stack<int>&st)
{
    visited[u]=inprocess[u]=true;
    for(auto v: adj[u])
    {
        if(!visited[v])isdag(v,adj,visited,inprocess,test,st);
        else if(inprocess[v])test=true;
    }
    inprocess[u]=false;
    st.push(u);
}
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
       for(int i=0;i<prerequisites.size();i++)
       {
        adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
       } 
       vector<bool>visited(numCourses,false),inprocess(numCourses,false);
       bool test=false;
       vector<int>ans;
       stack<int>st;
       for(int i=0;i<numCourses;i++)
       {
        if(!visited[i])isdag(i,adj,visited,inprocess,test,st);
       }
       if(test)return ans;
       while(!st.empty())
       {
        ans.push_back(st.top());
        st.pop();
       }
       reverse(ans.begin(),ans.end());
       return ans;
    }
};
