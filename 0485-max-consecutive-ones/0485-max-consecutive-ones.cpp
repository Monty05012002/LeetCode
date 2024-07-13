class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans=0,countones=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                ans=max(ans,countones);
                countones=0;
            }
            else{
                countones++;
            }
        }
        ans=max(ans,countones);
        return ans;
    }
};