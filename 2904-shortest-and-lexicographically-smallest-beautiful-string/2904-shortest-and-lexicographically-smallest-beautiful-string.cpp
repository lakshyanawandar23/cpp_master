class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        vector<string>ans;
        int i=0,j=0,cnt=0,len=100;
        while(j<s.size()){
            if(s[j]=='1'){
                cnt++;
            }
            while(i<=j&&cnt>k){
                if(s[i]=='1'){
                    cnt--;
                }
                i++;
            }
            if(cnt==k){
                while(s[i]=='0'){
                    i++;
                }
                len=min(len,j-i+1);
                string res=s.substr(i,j-i+1);
               // cout<<res<<endl;
                ans.push_back(res);
            }
            j++;
        }
       sort(ans.begin(),ans.end());
      for(auto it:ans){
          if(it.size()==len){
              return it;
          }
       //   cout<<it<<endl;
      }
        return "";
    }
};