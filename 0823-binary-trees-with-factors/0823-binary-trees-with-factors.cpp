class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        unordered_map<int,int>m;
        sort(arr.begin(),arr.end());
        for(auto it:arr){
        m[it]++;
        }
    long long int cnt=0,mod=1000000007;
        for(int i=0;i<arr.size();i++){
            long long int ans=1;
            for(int j=0;j<i;j++){
                if(arr[i]%arr[j]==0&&m.find(arr[i]/arr[j])!=m.end()){
                    ans+=((m[arr[j]]%mod)*(m[arr[i]/arr[j]]%mod)%mod)%mod;
                }
            }
            m[arr[i]]=ans%mod;
        }
        for(auto it:m){
            cnt=(cnt+it.second)%mod;
        }
        return cnt;
    }
};