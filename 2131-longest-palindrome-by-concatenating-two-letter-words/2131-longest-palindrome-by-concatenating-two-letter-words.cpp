class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int>mp;
        int length=0;
        for(auto it:words){
            string temp=it;
            reverse(temp.begin(),temp.end());
            if(mp[temp]>0){
                length+=4;
                mp[temp]--;
            }
            else
                mp[it]++;
        }
         for(auto [i,j] : mp){
            if(j==1){
                if(i[0]==i[1]) return length+2;           
            }
         }
        return length;
    }
};