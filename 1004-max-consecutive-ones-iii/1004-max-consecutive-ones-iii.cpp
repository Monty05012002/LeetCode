class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0,j=0,maxi=INT_MIN,zero=0;
        while(j<nums.size()){
            if(nums[j]==0)zero++;
            while(zero>k){
                if(nums[i]==0)zero--;
                i++;
            }
            maxi=max(maxi,j-i+1);
            j++;
        }
        return maxi;
    }
};