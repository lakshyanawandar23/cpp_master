class Solution {
public:
    bool check(int i,int j,string &s){
        if(i>j){
            return true;
        }
        if(s[i]==s[j]){
            return check(i+1,j-1,s);
        }
        return false;
    }
    string longestPalindrome(string s) {
        int ans=0,st=0;
        for(int i=0;i<s.size();i++){
            for(int j=i;j<s.size();j++){
                if(check(i,j,s)){
                    if((j-i+1)>ans){
                        ans=(j-i+1);
                       // cout<<ans<<endl;
                        st=i;
                    }
                }
            }
        }
        return s.substr(st,ans);
    }
};