class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        int ans=1,idx=0,cnt=0,prev=0;
        for(int i=1;i<s.size();i++){
            if(s[i]==s[i-1]){
               if(cnt==1){
                   idx=prev;
                   prev=i;
                   ans=max(ans,(i-idx+1));
                 //  cout<<ans<<endl;
                   cnt=1;
               }
                else {
                   ans=max(ans,(i-idx+1));
                   // cout<<ans<<endl;
                    cnt=1;
                    prev=i;
                }
            }
            else {
                ans=max(ans,(i-idx+1));
            }
        }
        return ans;
    }
};