class Cmp {
    public:
    bool operator() (pair<int, string> a, pair<int, string> b) {
        if(a.first == b.first)
            return a.second > b.second;
        else
            return a.first < b.first;
    }
};
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
         unordered_map<string,int>mp;
        for(int i=0;i<words.size();i++){
            mp[words[i]]++;
        }
         priority_queue<pair<int,string>,vector<pair<int,string>>,Cmp>ans;
        for(auto it:mp){
            ans.push({it.second,it.first});
        }
        vector<string>v;
        while(k--){
            v.push_back(ans.top().second);
            ans.pop();
        }
        return v;
    }
};