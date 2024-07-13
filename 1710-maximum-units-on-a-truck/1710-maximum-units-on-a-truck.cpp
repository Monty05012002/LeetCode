class Solution {
public:
    static bool Function(vector<int>&a,vector<int>&b){
        return a[1]>b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),Function);
        int ans=0;
        for(auto &x:boxTypes){
            if(truckSize==0) break;
            int temp=min(truckSize,x[0]);
            ans+=x[1]*temp;
            truckSize-=temp;
        }
        return ans;
    }
};