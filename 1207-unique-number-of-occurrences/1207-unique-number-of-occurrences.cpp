class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }
        vector<int>ans;
        for(auto it:mp){
            ans.push_back(it.second);
        }
        unordered_set<int>s;
        for(int i=0;i<ans.size();i++){
            s.insert(ans[i]);
        }
        int a=ans.size();
        int b=s.size();
        if(a==b)
            return true;
        else
            return false;
    }
};