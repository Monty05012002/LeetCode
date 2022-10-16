class Solution {
public:
    void solve(int open,int close,string op,vector<string>&s){
        if(open==0 && close==0){
            s.push_back(op);
            return;
        }
        if(open!=0){
            string op1=op;
            op1.push_back('(');
            solve(open-1,close,op1,s);
        }
        if(close>open){
            string op2=op;
            op2.push_back(')');
            solve(open,close-1,op2,s);
        }
    }
    vector<string> generateParenthesis(int n) {
        int open=n,close=n;
        vector<string>s;
        string op="";
        solve(open,close,op,s);
        return s;
    }
};