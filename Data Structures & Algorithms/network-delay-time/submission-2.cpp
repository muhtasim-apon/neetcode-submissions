class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
       vector<vector<pair<int,int>>>adj(n+1);
       priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
       vector<int>dist(n+1,INT_MAX);
       vector<bool>visited(n+1,false);
       for(int i=0;i<times.size();i++)
       {
        adj[times[i][0]].push_back({times[i][1],times[i][2]});
        //adj[times[i][1]].push_back({times[i][0],times[i][2]});
       }
        dist[k]=0;
         int ans=0;
        pq.push({dist[k],k});
        while(!pq.empty())
        {
            int d=pq.top().first;
            int u=pq.top().second;
            visited[u]=true;
            pq.pop();
            if(d>dist[u])continue;
            for(auto v:adj[u])
            {
                int v1=v.first;
                int w=v.second;
                if(!visited[v1])
                {
                if(d+w<dist[v1])
                {dist[v1]=d+w;
                pq.push({dist[v1],v1});
                //ans=max(ans,dist[v1]);
            }
            }
        }
        }
        for(auto x:dist)cout<<x<<" ";

        if(find(dist.begin()+1,dist.end(),INT_MAX)!=dist.end())return -1;
            return *max_element(dist.begin()+1,dist.end());
       } 

};
