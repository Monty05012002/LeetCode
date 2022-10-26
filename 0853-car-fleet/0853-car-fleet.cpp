class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        map<int,double>mp;
        for(int i=0;i<position.size();i++){
            double dis=(double)(target-position[i])/speed[i];
            mp[position[i]]=dis;
        }
        int fleet=0;
        double minimum=0;
        for(auto it=mp.rbegin();it!=mp.rend();it++){
            if(it->second>minimum){
                minimum=it->second;
                fleet++;
            }
        }
        return fleet;
    }
};