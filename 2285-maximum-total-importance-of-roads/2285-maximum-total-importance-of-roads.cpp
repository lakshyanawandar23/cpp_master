class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& s) {
        long long int ans=0;
        vector<long long int>v(n,0);
        for(int i=0;i<s.size();i++){
            v[s[i][0]]++;
            v[s[i][1]]++;
        }
        sort(v.begin(),v.end(),greater<int>());
    long long    int cnt=n;
        for(int i=0;i<n;i++){
            long long int res=(long long int)(cnt*v[i]);
            ans+=res;
            cnt--;
        }
        return ans;
    }
};