class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
       vector<pair<int,int>>v;
        for(int i=0;i<position.size();i++){
            v.push_back({position[i],speed[i]});
        }
        sort(v.begin(),v.end());
        stack<double>st;
        for(int i=v.size()-1;i>=0;i--){
             double t = (target-v[i].first)/((double)v[i].second);  
            
              if(st.empty() || st.top()<t)
              {
                  st.push(t);
              }
        }
        return st.size();}
};