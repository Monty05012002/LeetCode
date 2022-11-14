class DisjointSet{
    public:
        vector<int>size,parent;
        DisjointSet(int n){
            size.resize(n+1,1);
            parent.resize(n+1);
            for(int i=0;i<n;i++){
                parent[i]=i;
            }
        }
        int findUParent(int node){
            if(node==parent[node])return node;
            return parent[node]=findUParent(parent[node]);
        }

        void unionS(int u,int v){
            int up_u=findUParent(u);
            int up_v=findUParent(v);
            if(up_u==up_v)return;
            if(size[up_u]>size[up_v]){
                parent[up_v]=up_u;
                size[up_u]+=size[up_v];
            }
            else{
                parent[up_u]=up_v;
                size[up_v]+=size[up_u];
            }
        }

};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        int maxRow=0,maxCol=0;
        for(auto it:stones){
            maxRow=max(maxRow,it[0]);
            maxCol=max(maxCol,it[1]);
        }
        DisjointSet ds(maxRow+maxCol+2);
        unordered_map<int,int>mp;
        for(auto it:stones){
            int nodeR=it[0];
            int nodeC=it[1]+maxRow+1;
            ds.unionS(nodeR,nodeC);
            mp[nodeR]=1;
            mp[nodeC]=1;
        }
          int cnt=0;

        for(auto it:mp){
            if(ds.findUParent(it.first)==it.first){
                cnt++;
            }
        }
        return n-cnt;
    }
};