class DisjointSet{
    public:
        vector<int>size,parent;
        DisjointSet(int n){
            size.resize(n+1,0);
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
                size[up_v]+=size[up_u];
            }
            else{
                parent[up_v]=up_u;
                size[up_u]+=size[up_v];
            }
        }

};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& edge) {
          DisjointSet ds(n);
        int ced=0;
        for(auto it:edge)
        {
            int u=it[0];
            int v=it[1];
            if(ds.findUParent(u)==ds.findUParent(v))
            ced++;
            else
            ds.unionS(u,v);
        }
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(ds.parent[i]==i)
            cnt++;
        }
        int ans=cnt-1;
        if(ced>=ans) return ans;
        return -1;
    }
};