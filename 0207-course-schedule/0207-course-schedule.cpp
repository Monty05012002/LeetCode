class Solution {
public:
    bool canFinish(int V, vector<vector<int>>& prerequisites) {
        vector<int>adj[V];
        for(auto it:prerequisites){
            adj[it[1]].push_back(it[0]);
        }
         vector<int> indegree(V);
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }
	    queue<int>q;
	    for(int i=0;i<V;i++){
	        if(indegree[i]==0)
	         q.push(i);
	    }
	    vector<int>ans;
	    while(!q.empty()){
	        int start=q.front();
	        q.pop();
	        ans.push_back(start);
	        for(auto it:adj[start]){
	            indegree[it]--;
	            if(indegree[it]==0)
	            q.push(it);
	        }
	    }
	    if(ans.size()==V)
            return true;
        return false;
    }
};