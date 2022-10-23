class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int,int>mp;
        vector<int>ans;
       for(int i=0;i<nums.size();i++){
          if(mp.find(nums[i])!=mp.end()){
              ans.push_back(nums[i]);
          }
           mp[nums[i]]++;
       }
        for(int i=1;i<=nums.size();i++){
            if(mp.find(i)==mp.end()){
                ans.push_back(i);
                    break;
                }
        }
        return ans;
    }
};