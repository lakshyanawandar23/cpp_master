class Solution {
public:
    int countHomogenous(string s) {
        int cnt=1,ans=1,m=1e9+7;
        for(int i=1;i<s.size();i++){
            if(s[i]!=s[i-1]){
                cnt=1;
                ans=((ans%m)+(cnt%m))%m;
            }
            else{
                cnt=(cnt%m)+1;
                  ans=((ans%m)+(cnt%m))%m;
            }
        }
        return ans;
    }
};