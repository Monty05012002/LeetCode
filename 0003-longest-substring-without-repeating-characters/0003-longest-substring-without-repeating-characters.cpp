class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mp;
        int i=0,j=0,maxi=0;
        while(j<s.size()){
            mp[s[j]]++;
            if(mp.size()<(j-i+1)){
                    mp[s[i]]--;
                    if(mp[s[i]]==0) mp.erase(s[i]);
                    i++;   
            }
            maxi=max(maxi,j-i+1);
            j++;
        }
        return maxi;
    }
};