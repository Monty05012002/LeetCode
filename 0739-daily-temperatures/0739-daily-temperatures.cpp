class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>>s;
        int n=temperatures.size();
        vector<int>v,ans(n);
        for(int i=n-1;i>=0;i--){
            if(s.size()==0){
                v.push_back(0);
            }
            else if(s.size()>0 && s.top().first>temperatures[i]){
                v.push_back(s.top().second);
            }
            else if(s.size()>0 && s.top().first<=temperatures[i]){
                while(s.size()>0 && s.top().first<=temperatures[i])
                    s.pop();
                if(s.size()==0)
                    v.push_back(0);
                else
                    v.push_back(s.top().second);
            }
            s.push({temperatures[i],i});
        }
        reverse(v.begin(),v.end());
        for(int i=0;i<n;i++){
            if(v[i]!=0){
                ans[i]=v[i]-i;
            }
            else
                ans[i]=0;
        }
        return ans;
    }
};