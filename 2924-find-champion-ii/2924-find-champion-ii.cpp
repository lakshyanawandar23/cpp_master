class Solution {
public:
    int findChampion(int n, vector<vector<int>>& e) {
        vector<int>v(n,0);
        int ans=-1,cnt=0;
        for(auto it:e){
            v[it[1]]++;
        }
        for(int i=0;i<n;i++){
            if(v[i]==0){
                ans=i;
                cnt++;
            }
        }
        return cnt>1?-1:ans;
    }
};