class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& c, int e) {
        vector<bool>v;
        int ans=0;
        for(auto it:c){
            ans=max(ans,it);
        }
        for(int i=0;i<c.size();i++){
            if(c[i]+e>=ans){
                v.push_back(true);
            }
            else{
                v.push_back(false);
            }
           // ans=max(ans,c[i]+e);
        }
        return v;
    }
};