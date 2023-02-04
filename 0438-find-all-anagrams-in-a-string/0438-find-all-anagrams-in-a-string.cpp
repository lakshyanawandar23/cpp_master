class Solution {
public:
    bool solve(vector<int>a,vector<int>b){
        for(int i=0;i<26;i++){
            if(a[i]!=b[i]){
                return false;
            }
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
    vector<int>a(26,0);
         vector<int>b(26,0);
        for(int i=0;i<p.size();i++){
            a[p[i]-'a']++;
        }
        int j=0;
        vector<int>ans;
        for(int i=0;i<s.size();i++){
            b[s[i]-'a']++;
            if(i-j+1==p.size()){
                if(solve(a,b)){
                    ans.push_back(j);
                }
                b[s[j]-'a']--;
                j++;
            }
        }
        return ans;
    }
};