class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string ans,res;
        for(int i=0;i<s.size();i++){
          if(s[i]=='#'&&ans.size()>0){
              ans.pop_back();
          }
            else if(s[i]!='#'){
                ans+=s[i];
            }
        }
         for(int i=0;i<t.size();i++){
          if(t[i]=='#'&&res.size()>0){
              res.pop_back();
          }
            else if(t[i]!='#'){
                res+=t[i];
            }
        }
      //  cout<<ans<<" "<<res<<endl;
        return ans==res;
    }
};