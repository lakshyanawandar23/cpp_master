class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int>occur[26];
        for(int i=0;i<s.size();i++){
            int idx=s[i]-'a';
            occur[idx].push_back(i);
        }
        int cnt=0;
        for(int i=0;i<26;i++){
            int n=occur[i].size();
            if(n==0) continue;
            int f=occur[i][0];
            int l=occur[i][n-1];
            for(int j=0;j<26;j++){
              
                int idx=upper_bound(occur[j].begin(),occur[j].end(),f)-occur[j].begin();
                
                  if(occur[j].size()==idx) continue;
                int k=occur[j][idx];
                if(f<k&&l>k)  cnt++;
            }
        }
        return cnt;
    }
};