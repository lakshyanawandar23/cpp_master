class Solution {
public:
    int maxSubstrings(string s) {
        int cnt=0;
        unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++){
        if(mp.find(s[i])!=mp.end()&&(i-mp[s[i]]+1)>=4){
            mp.clear();
            cnt++;
        }
         else if(mp.find(s[i])==mp.end()) {
           // cout<<i<<endl;
             mp[s[i]]=i;
         }
        }
        return cnt;
    }
};