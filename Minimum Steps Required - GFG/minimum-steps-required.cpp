//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

int minSteps(string str) {
    // Write your code here.
    char c=str[0];
    int count=1;
    for(int i=1;i<str.size();i++){
        if(c==str[i])
        continue;
        else{
            count++;
            while(i<str.size() && str[i]!=c)
            i++;
        }
    }
    return count;
}

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        cout << minSteps(str) << endl;
    }
}

// } Driver Code Ends