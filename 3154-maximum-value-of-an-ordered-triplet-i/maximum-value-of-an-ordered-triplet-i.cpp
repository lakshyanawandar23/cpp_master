class Solution {
public:
    long long maximumTripletValue(vector<int>& num) {
        int n=num.size();
        vector<int>pre(n);
        vector<int>suf(n);
        pre[0]=num[0];
        for(int i=1;i<n;i++){
          pre[i]=max(pre[i-1],num[i-1]);
        }
        suf[n-1]=num[n-1];
        for(int i=n-2;i>=0;i--){
        suf[i]=max(suf[i+1],num[i+1]);
        }
        long long int ans=0;
        for(int i=1;i<n-1;i++){
          //  cout<<pre[i]<<" "<<suf[i]<<endl;
            long long int diff=(pre[i]-num[i]);
            long long int res=diff*suf[i];
            ans=max(ans,res);
        }
        return ans;
    }
};