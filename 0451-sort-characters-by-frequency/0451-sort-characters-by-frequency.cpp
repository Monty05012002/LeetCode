class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
         priority_queue<pair<int,char>>maxh;
        for(auto it:mp){
            maxh.push({it.second,it.first});
        }
        string str="";
        while(!maxh.empty()){
            pair<int,char>v=maxh.top();
            while(v.first--)
            str+=v.second;
            maxh.pop();
        }
        return str;
    }
};