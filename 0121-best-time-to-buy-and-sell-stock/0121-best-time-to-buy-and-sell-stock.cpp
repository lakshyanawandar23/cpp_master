class Solution {
public:
    int maxProfit(vector<int>& p) {
        int ans=0,curr=INT_MAX;
        for(int i=0;i<p.size();i++){
            curr=min(curr,p[i]);
            ans=max(ans,abs(curr-p[i]));
        }
        return ans;
    }
};