class Solution {
public:
    int candy(vector<int>& s) {
        vector<int>ans(s.size(),1);
        for(int i=1;i<s.size();i++){
            if(s[i]>s[i-1]){
                ans[i]=ans[i-1]+1;
            }
        }
        for(int i=s.size()-2;i>=0;i--){
            if(s[i]>s[i+1]){
       ans[i]=max(ans[i],1+ans[i+1]);
            }
        }
        int cnt=0;
        for(auto it:ans){
            cnt+=it;
        }
        return cnt;
    }
};