class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>>adj[n];
        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        queue<pair<int,pair<int,int>>>q;
        vector<int>dist(n,1e9);
        dist[src]=0;
        q.push({0,{src,0}});
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int stops=it.first;
            int node=it.second.first;
            int dis=it.second.second;
            for(auto i:adj[node]){
                int adjnode=i.first;
                int ew=i.second;
                if(stops>k)
                    continue;
                if(dis+ew<dist[adjnode] && stops<=k){
                    dist[adjnode]=dis+ew;
                    q.push({stops+1,{adjnode,dis+ew}});
                }
            }
        }
        if(dist[dst]==1e9)
            return -1;
        return dist[dst];
    }
};