class Solution {
public:
    int characterReplacement(string s, int k) {
        int i=0,j=0,ans=INT_MIN,maxi=INT_MIN;
        unordered_map<char,int>mp;
        while(j<s.size()){
            mp[s[j]]++;
            maxi=max(maxi,mp[s[j]]);
            if((j-i+1)-maxi>k){
                mp[s[i]]--;
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};