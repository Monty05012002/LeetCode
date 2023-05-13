//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool lemonadeChange(int N, vector<int> &bills) {
        // code here
        int c5=0,c10=0;
        for(int i=0;i<N;i++){
            if(bills[i]==5){
                c5++;
            }else if(bills[i]==10){
                if(c5==0) return false;
                c10++;
                c5--;
            }else {
                if(c5>0 && c10>0){
                 c5--;
                 c10--;
                }
                else if(c5>=3) c5-=3;
                else return false;
            }
        }
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> bills(N);
        for (int i = 0; i < N; i++) cin >> bills[i];

        Solution obj;
        int ans = obj.lemonadeChange(N, bills);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends