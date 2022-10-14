class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        stack<pair<int ,int>>s,s1;
        int n=arr.size();
        vector<int>right,left;
        vector<int>width(n),area(n);
        for(int i=n-1;i>=0;i--){
            if(s.size()==0){
                right.push_back(n);
            }
            else if(s.size()>0 && s.top().first<arr[i]){
                right.push_back(s.top().second);
            }
            else if(s.size()>0 && s.top().first>=arr[i]){
                while(s.size()>0 && s.top().first>=arr[i])
                s.pop();
                if(s.size()==0)
                right.push_back(n);
                else
                right.push_back(s.top().second);
            }
            s.push({arr[i],i});
        }
        reverse(right.begin(),right.end());
        for(int i=0;i<n;i++){
            if(s1.size()==0){
                left.push_back(-1);
            }
            else if(s1.size()>0 && s1.top().first<arr[i]){
                left.push_back(s1.top().second);
            }
            else if(s1.size()>0 && s1.top().first>=arr[i]){
                while(s1.size()>0 && s1.top().first>=arr[i])
                s1.pop();
                if(s1.size()==0)
                left.push_back(-1);
                else
                left.push_back(s1.top().second);
            }
            s1.push({arr[i],i});
        }
        for(int i=0;i<n;i++){
            width[i]=right[i]-left[i]-1;
        }
        int maxproduct=0;
        for(int i=0;i<n;i++){
           area[i]=width[i]*arr[i];
        }
        for(int i=0;i<n;i++){
            if(area[i]>maxproduct){
                maxproduct=area[i];
            }
        }
        return maxproduct;

    }
};