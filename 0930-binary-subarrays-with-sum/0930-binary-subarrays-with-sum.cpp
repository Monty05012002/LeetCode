class Solution {
public:
    int solve(int goal,vector<int>&nums){
        if(goal<0)return 0;
         int i=0,j=0,sum=0,ans=0;
        while(j<nums.size()){
            sum+=nums[j];
            if(sum>goal){
                while(sum>goal){
                    sum-=nums[i];
                    i++;
                }
            }
            ans+=(j-i+1);
            j++;
        }
        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return solve(goal,nums)-solve(goal-1,nums);
    }
};