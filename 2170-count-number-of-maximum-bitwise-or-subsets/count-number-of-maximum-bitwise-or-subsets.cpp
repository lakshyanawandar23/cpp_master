class Solution {
public:
int cnt;
 void solve(vector<int>&num,int &x,int i,int curr){
    if(i==num.size()){
        if(x==curr) cnt++;
        return ;
    }
    solve(num,x,i+1,curr);
    solve(num,x,i+1,curr|num[i]);
    return ;
 }
    int countMaxOrSubsets(vector<int>& num) {
        int x=0;
        for(auto it:num){
            x|=it;
        }
         cnt=0;
         solve(num,x,0,0);
         return cnt;
    }
};