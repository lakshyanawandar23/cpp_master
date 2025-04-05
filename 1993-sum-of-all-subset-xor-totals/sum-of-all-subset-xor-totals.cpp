class Solution {
public:
int tot;
 void solve(int i,int x,int n,vector<int>&num){
    if(i>=n){
        tot+=x;
        return;
    }
     solve(i+1,x,n,num);
     solve(i+1,x^num[i],n,num);
     return ;
 }
    int subsetXORSum(vector<int>& num) {
        int n=num.size();
      tot=0;
      solve(0,0,n,num);
      return tot;
    }
};