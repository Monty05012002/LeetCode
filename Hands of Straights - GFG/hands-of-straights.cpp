//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isStraightHand(int N, int groupSize, vector<int> &hand) {
        // code here
         map<int,int>mp;
        for(auto it:hand) mp[it]++;
        priority_queue<int,vector<int>,greater<int>>minh;
        for(auto it:mp) minh.push(it.first);
        while(!minh.empty()){
            int top=minh.top();
            for(int i=top;i<top+groupSize;i++){
                if(mp.find(i)==mp.end()) return false;
                mp[i]--;
                if(mp[i]==0){
                    if(i!=minh.top()) return false;
                    minh.pop();
                }
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
        int N, groupSize;
        cin >> N >> groupSize;

        vector<int> hand(N);
        for (int i = 0; i < N; i++) cin >> hand[i];

        Solution obj;
        int ans = obj.isStraightHand(N, groupSize, hand);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends