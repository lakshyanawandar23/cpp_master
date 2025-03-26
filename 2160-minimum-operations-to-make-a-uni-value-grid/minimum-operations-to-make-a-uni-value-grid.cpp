class Solution {
public:
    int minOperations(vector<vector<int>>& g, int x) {
        int n=g.size(),m=g[0].size();
        vector<int>v;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                v.push_back(g[i][j]);
            }
        }
        sort(v.begin(),v.end());
        int cnt=0,n1=v.size(),idx=n1/2;
        for(auto it:v){
            int rem=abs(it-v[idx]);
            if(rem%x!=0) return -1;
            cnt+=(rem/x);
        }
        return cnt;

    }
};