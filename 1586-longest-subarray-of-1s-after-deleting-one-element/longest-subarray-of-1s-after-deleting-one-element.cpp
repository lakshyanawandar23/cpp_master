class Solution {
public:
    int longestSubarray(vector<int>& num) {
        int n=num.size(),f=0,prev=0,ans=0;
        bool flag=true;
         for(int i=0;i<n;i++){
             if(num[i]==0){
                flag=false;
                if(i>0&&num[i-1]==0){
                    ans=max(ans,f);
                    f=0;
                    prev=0;
                }
              else {
               
                prev=f;
                f=0;
              }
             }
             else {
                f++;
                ans=max(ans,prev+f);
             }
         }
         if(flag) return ans-1;
         return ans;
    }
};