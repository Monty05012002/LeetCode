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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
          int n=accounts.size();
        DisjointSet ds(n);
        unordered_map<string,int>mp;
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
            string str=accounts[i][j];
            if(mp.find(str)==mp.end()){
                mp[str]=i;
                
            }
            else{
                ds.unionS(i,mp[str]);
              }
            }
           }
        vector<string>v[n];
        for(auto it:mp){
            int nod=ds.findUParent(it.second);
            string s=it.first;
            v[nod].push_back(s);
        }
        vector<vector<string>>ans;
        for(int i=0;i<n;i++){
            if(v[i].size()==0) continue;
            sort(v[i].begin(),v[i].end());
            vector<string>temp;
            temp.push_back(accounts[i][0]);
            for(auto it:v[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};