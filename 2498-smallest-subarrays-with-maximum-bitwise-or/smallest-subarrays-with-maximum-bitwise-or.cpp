class Solution {
public:
  void solve(int t,vector<int>&last,int i){
    int j=0;
    while(t){
       if(t%2){
          last[j]=i;
       }
       j++;
       t=t/2;
    }
    return ;
  }
    vector<int> smallestSubarrays(vector<int>& num) {
        int n=num.size()-1;
        vector<int>last(32,-1);
        vector<int>ans(n+1);
        for(int i=n;i>=0;i--){
            solve(num[i],last,i);
            int maxi=-1;
            for(int j=0;j<32;j++){
                maxi=max(maxi,last[j]);
            }
         if(maxi>-1)  ans[i]=(maxi-i+1);
         else ans[i]=1;

        }
        return ans;
    }
};