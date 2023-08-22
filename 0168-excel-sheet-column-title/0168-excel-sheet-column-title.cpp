class Solution {
public:
    string convertToTitle(int c) {
        if(c<=26) {
            string ans;
            ans+='A'+(c-1);
            return ans;
        }
        string ans;
        while(c>0){
            int mod=c%26;
            if(mod==0) {
                ans+='Z';
                c=c/26-1;
            }
            else{
        ans+=('A'+(mod-1));
                c=c/26;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};