class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans=0;
        unordered_map<char,int>mp;
        int i=0,n=s.size();
        for(int j=0;j<n;j++){
            if(mp.find(s[j])==mp.end()){
                mp[s[j]]++;
            }
            else
             {
                while(i<j&&mp.find(s[j])!=mp.end()){
                mp[s[i]]--;
                mp.erase(s[i]);
               i++;
                }
                mp[s[j]]++;
            //i++;
            }
            ans=max(ans,j-i+1);
        }
        return ans;
    }
};