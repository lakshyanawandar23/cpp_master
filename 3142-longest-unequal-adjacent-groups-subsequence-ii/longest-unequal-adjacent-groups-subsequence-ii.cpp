class Solution {
public:
bool hamming(string a,string b){
    int cnt=0;
    if(a.size()!=b.size()) return false;
    for(int i=0;i<a.size();i++){
        if(a[i]!=b[i]) cnt++;
    }
    return cnt>1?false:true;
}
    vector<string> getWordsInLongestSubsequence(vector<string>& w, vector<int>& g) {
        int n=w.size(),ls=0,idx=0;
        vector<int>dp(n+1,1);
        vector<int>parent(n+1,-1);
     for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(g[i]!=g[j]&&hamming(w[i],w[j])){
                if(dp[i]<(1+dp[j])){
                    dp[i]=1+dp[j];
                         parent[i]=j;
                    if(ls<dp[i]){
                        // cout<<i<<endl;
                        ls=dp[i];
                        idx=i;
                   
                    }
                }
            }
        }
     }
       vector<string>ans;
      // cout<<parent[6]<<endl;
       while(idx!=-1){
        ans.push_back(w[idx]);
        idx=parent[idx];
       }
       reverse(ans.begin(),ans.end());
       return ans;
    }
};