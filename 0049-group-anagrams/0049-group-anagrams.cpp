class Solution {
public:
    string generate(string &s) {
        int count[26] = {0};
        
        for(char &ch : s) {
            count[ch-'a']++;
        }
        
        string str;
        
        for(int i = 0; i<26; i++) {
            
            if(count[i] > 0) {
                str += string(count[i], i+'a');
            }
        }
        return str;
    }
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        
        for(string &s : strs) {
            string s1 = generate(s);
            
            mp[s1].push_back(s);
        }
        
        vector<vector<string>> result;
        for(auto &it : mp) {
            result.push_back(it.second);
        }
        
        return result;
        
    }
};