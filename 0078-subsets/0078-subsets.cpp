class Solution {
public:
    vector<vector<int>>ans;
   void solve(vector<int> number ,vector<int> v){
    if(number.size()==0)
    return;
    
    int temp=number[number.size()-1];
       number.pop_back();
    solve(number,v);
    
    
    v.push_back(temp);
    solve(number,v);
    ans.push_back(v);
    
}
   

vector<vector<int>> subsets(vector<int>& nums) {
    
    vector<int> v;
    ans.push_back(v);
    solve(nums,v);
    return ans;
}
};