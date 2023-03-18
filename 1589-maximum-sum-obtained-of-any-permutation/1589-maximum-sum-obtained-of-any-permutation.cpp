class Solution {
public:
    int maxSumRangeQuery(vector<int>& num, vector<vector<int>>& q) {
        int n=num.size();
        vector<int>v(n+1,0);
        for(auto val:q){
            int f=val[0];
            int l=val[1];
         v[f]++;
            v[l+1]--;
        }
        for(int i=1;i<=n;i++){
            v[i]+=v[i-1];
             //  cout<<v[i]<<endl;
        }
        sort(num.begin(),num.end());
        sort(v.begin(),v.end(),greater<int>());
    long long    int ans=0,m=1000000007,j=n-1;
        for(int i=0;i<n;i++){
            ans+=(long long int)(num[j])*(long long int)(v[i]);
            ans=ans%m;
            j--;
        }
        return ans;
    }
};