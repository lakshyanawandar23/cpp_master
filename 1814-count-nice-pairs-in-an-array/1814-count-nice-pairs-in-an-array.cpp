class Solution {
public:
    int countNicePairs(vector<int>& num) {
        int n=num.size(),mod=1e9+7,cnt=0;
        unordered_map<int,int>m;
        for(int i=0;i<n;i++){
            string res=to_string(num[i]);
            reverse(res.begin(),res.end());
            int ans=stoi(res);
            if(m.find((num[i]-ans))!=m.end()){
                cnt=((cnt%mod)+(m[num[i]-ans])%mod)%mod;
            }
         (m[num[i]-ans])++;
        }
        return cnt;
    }
};