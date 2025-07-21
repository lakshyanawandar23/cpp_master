class Solution {
public:
    string makeFancyString(string s) {
           unordered_map<int,int>mp;
           int cnt=1;
           for(int i=1;i<s.size();i++){
            if(s[i]==s[i-1]){
                cnt++;
                if(cnt>=3){
                    mp[i]++;
                }
            }
            else {
                cnt=1;
            }
           }
           string ans;
           for(int i=0;i<s.size();i++){
                     if(mp.find(i)==mp.end()) ans+=s[i];
           }
           return ans;
    }
};