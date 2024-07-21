class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
         unordered_map<string,vector<string>>mp;
         for(auto it:strs){
             string temp=it;
             sort(temp.begin(),temp.end());
             if(mp.find(temp)!=mp.end()){
                 mp[temp].push_back(it);
             }
             else{
                 mp[temp].push_back(it);
             }
         }
        vector<vector<string>>ans;
        for(auto it:mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};