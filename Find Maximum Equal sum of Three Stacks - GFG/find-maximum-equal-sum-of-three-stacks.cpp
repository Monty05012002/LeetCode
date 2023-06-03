//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxEqualSum(int N1,int N2,int N3,vector<int> &S1,vector<int> &S2,vector<int> &S3){
        long long sum1=0,sum2=0,sum3=0;
        for(int i=0;i<S1.size();i++){
            sum1+=S1[i];
        }
        for(int i=0;i<S2.size();i++){
            sum2+=S2[i];
        }
        for(int i=0;i<S3.size();i++){
            sum3+=S3[i];
        }
        if(sum1==0 && sum2==0 && sum3==0)
        return 0;
        int i1=0,i2=0,i3=0;
        while(true){
            if(sum1==sum2 && sum1==sum3)
            return sum1;
            int miniSum=min(sum1,min(sum2,sum3));
            if(i1<N1 && sum1>miniSum)
            sum1-=S1[i1++];
             if(i2<N2 && sum2>miniSum)
            sum2-=S2[i2++];
             if(i3<N3 && sum3>miniSum)
            sum3-=S3[i3++];
        }
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n1,n2,n3;
        cin>>n1>>n2>>n3;
        vector<int> s1(n1),s2(n2),s3(n3);
        for(int i=0;i<n1;i++){
            cin>>s1[i];
        }
        for(int i=0;i<n2;i++){
            cin>>s2[i];
        }
        for(int i=0;i<n3;i++){
            cin>>s3[i];
        }
        Solution ob;
        int ans=ob.maxEqualSum(n1,n2,n3,s1,s2,s3);
        cout<<ans<<endl;
    }
    
    return 0;
}
// } Driver Code Ends