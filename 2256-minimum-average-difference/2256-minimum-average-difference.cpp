class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long long int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
       long long int a=0,b=0,bsum=0;
        int mini=INT_MAX,ans=0;
        for(int i=0;i<n;i++){
          bsum+=nums[i];
         sum-=nums[i];
           a=bsum/(i+1);
           b=(i==n-1)?0:sum/(n-i-1);
            if(abs(a-b)<mini)
            {
                ans=i;
                mini=abs(a-b);
            }
            
        }
       
        return ans;
        
    }
};