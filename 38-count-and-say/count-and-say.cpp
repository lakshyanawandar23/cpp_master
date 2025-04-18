class Solution {
public:
    string countAndSay(int n) {
        string ans="1";
        if(n==1) return ans;
        for(int i=1;i<n;i++){
        string res="";
        int cnt=1;
     //   cout<<ans<<endl;
         for(int j=1;j<ans.size();j++){
               if(ans[j]==ans[j-1]){
                cnt++;
               }
               else {
                res+=to_string(cnt);
              if(i>0)  res+=ans[j-1];
              else res+=ans[j];
                cnt=1;
               }
         }
        // cout<<res<<endl;
             res+=to_string(cnt);
             res+=ans[ans.size()-1];
           //  cout<<i<<" "<<res<<endl;
             ans=res;
            // cout<<ans<<endl;
        }
        return ans;
    }
};