class Solution {
public:
    int longestBalanced(string s) {
        int ans=0,n=s.size();
     
        for(int i=0;i<s.size();i++){
               vector<int>v(26,0);
               int cnt=0;
               for(int j=i;j<s.size();j++){
                   v[s[j]-'a']++;
                   cnt=max(cnt,v[s[j]-'a']);
                    if(n-i<=ans) break;
                    bool flag=true;
                    for(int k=0;k<26;k++){
                        if(v[k]>0&&cnt>v[k]){
                            flag=false;
                            break;
                        }
                    }
                    if(flag) ans=max(ans,j-i+1); 
               }
        }
        return ans;
    }
};