class Solution {
public:
    
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for(string &s : strs) {
            string s1 = s;
            sort(s.begin(),s.end());  
            mp[s].push_back(s1);
        }
        
        vector<vector<string>> result;
        for(auto &it : mp) {
            result.push_back(it.second);
        }
        
        return result;
        
    }
};