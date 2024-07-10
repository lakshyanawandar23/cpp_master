class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& c) {
        double ans=0;
        int prev=0;
        for(int i=0;i<c.size();i++){
            prev=max(prev,c[i][0]);
            int res=(prev+c[i][1]);
            ans+=(res-c[i][0]);
            prev=res;
        }
        return (ans/c.size()*1.0);
    }
};