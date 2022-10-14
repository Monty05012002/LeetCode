//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*
The structure of the class is as follows
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
*/

class Solution{
    int minEle;
    stack<int> s;
    public:
       int minele;
       int getMin()
       {
           if(s.empty()==true)
           {
               return -1;
           }
           return minele;
       }
       int pop()
       {
           if(s.empty()==true)
           {
               return -1;
           }
           else if(s.top()<minele)
           {
               int ele = minele;
               minele = 2*minele-s.top();
               s.pop();
               return ele;
           }
           else if(s.top()>=minele)
           {
               int ele = s.top();
               s.pop();
               return ele;
           }
       }
       void push(int x)
       {
            if(s.empty()==true)    
            {
                s.push(x);
                minele = x;
            }
            else if(minele<=x)
            {
                s.push(x);
            }
            else
            {
                s.push(2*x-minele);
                minele = x;
            }
       }
           
};

//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int q;
        cin>>q;
        Solution ob;
        while(q--){
           int qt;
           cin>>qt;
           if(qt==1)
           {
              //push
              int att;
              cin>>att;
              ob.push(att);
           }
           else if(qt==2)
           {
              //pop
              cout<<ob.pop()<<" ";
           }
           else if(qt==3)
           {
              //getMin
              cout<<ob.getMin()<<" ";
           }
       }
       cout<<endl;
    }
    return 0;
}

// } Driver Code Ends