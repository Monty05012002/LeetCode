//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    long long solve(int N, vector<int> &A, vector<int> &B) {
        // code here
        long long SumA=0,SumB=0;
        vector<int>EvenA,EvenB,OddA,OddB;
        for(int i=0;i<N;i++){
            SumA+=A[i];
            SumB+=B[i];
            if(A[i]%2==0){
                EvenA.push_back(A[i]);
            }
            else{
                OddA.push_back(A[i]);
            }
            if(B[i]%2==0){
                EvenB.push_back(B[i]);
            }
            else{
                OddB.push_back(B[i]);
            }
        }
        if(SumA!=SumB || OddA.size()!=OddB.size()) return -1;
        sort(OddA.begin(),OddA.end());
        sort(EvenA.begin(),EvenA.end());
        sort(OddB.begin(),OddB.end());
        sort(EvenB.begin(),EvenB.end());
        long long ans=0;
        for(int i=0;i<OddA.size();i++){
            ans+=abs(OddA[i]-OddB[i])/2;
        }
        for(int i=0;i<EvenA.size();i++){
            ans+=abs(EvenA[i]-EvenB[i])/2;
        }
        return ans/2;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<int> A(N);
        Array::input(A,N);
        
        
        vector<int> B(N);
        Array::input(B,N);
        
        Solution obj;
        long long res = obj.solve(N, A, B);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends