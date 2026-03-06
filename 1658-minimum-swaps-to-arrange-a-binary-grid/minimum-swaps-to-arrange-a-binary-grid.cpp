class Solution {
public:
    int minSwaps(vector<vector<int>>& g) {
        int n=g.size();
        vector<int>v;
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=n-1;j>=0;j--){
                if(g[i][j]==0) cnt++;
                else {
                    break;
                }
            }
            v.push_back(cnt);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int req=n-i-1;
            int j=i;

            while(j<n&&req>v[j]){
                j++;
            }
            if(j==n) return -1;
           while(j>i){
            swap(v[j],v[j-1]);
            j--;
            ans++;
           }
        }
        return ans;
    }
};