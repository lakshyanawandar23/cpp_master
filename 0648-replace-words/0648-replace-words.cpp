class Solution {
public:
    string replaceWords(vector<string>& d, string s) {
        int n=s.size();
        unordered_map<string,int>mp;
        for(int i=0;i<d.size();i++){
            mp[d[i]]++;
        }
        string res;
        for(int i=0;i<n;i++){
            string  ans,t="";
            while(i<n&&s[i]!=' '){
                ans+=s[i];
                if(mp.find(ans)!=mp.end()){
                  if(t!=""&&t.size()>ans.size()){
                      t=ans;
                  }
                    else if(t.size()==0) {
                        t=ans;
                    }
                }
                i++;
            }
            if(t.size()>0)
            res+=t;
            else res+=ans;
            res+=" ";
        }
        res.pop_back();
        return res;
    }
};