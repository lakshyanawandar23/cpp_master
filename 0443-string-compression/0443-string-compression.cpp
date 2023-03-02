class Solution {
public:
    int compress(vector<char>& s) {
        string ans;
        if(s.size()==1){
            return 1;
        }
        for(int i=0;i<s.size();){
            int cnt=0,j;
            for( j=i;j<s.size();j++){
                if(s[i]==s[j]){
                    cnt++;
                }
                else{
                    break;
                }
            }
            if(cnt>1){
             //   cout<<cnt<<endl;
                ans+=s[i];
                string res;
                while(cnt){
                    int mod=cnt%10;
                    res+=('0'+mod);
                    cnt/=10;
                }
                reverse(res.begin(),res.end());
                ans+=(res);
            }
            else{
                ans+=s[i];
            }
            i=j;
          // cout<<ans<<endl;
        }
          s.resize(ans.size());
        for(int i=0;i<ans.size();){
            s[i]=ans[i];
            i++;
            s[i]=ans[i];
            i++;
        }
        return s.size();
    }
};