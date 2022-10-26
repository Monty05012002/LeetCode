class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int i=0;
        int sum=0;
        if(nums.size()<2)
            return false;
        while(i<nums.size()){
            sum+=nums[i];
            sum%=k;
            if(sum==0 && i)
                return true;
            if(mp.find(sum)!=mp.end()){
                if(i-mp[sum]>1)
                    return true;
            }
            else
                mp[sum]=i;
            i++;
        }
        return false;
    }
};