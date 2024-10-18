class Solution {
public:
    int ans;
    void solve(vector<int>&num,int i,int &x,int curr){
        if(i==num.size()) return ;
        int t=curr|num[i];
    if(t==x) ans++;
        solve(num,i+1,x,curr);
        solve(num,i+1,x,t);
        return ;
    }
    int countMaxOrSubsets(vector<int>& num) {
        int  n=num.size(),x=0;
        for(auto it:num){
            x=x|it;
        }
        ans=0;
        solve(num,0,x,0);
        return ans;
    }
};