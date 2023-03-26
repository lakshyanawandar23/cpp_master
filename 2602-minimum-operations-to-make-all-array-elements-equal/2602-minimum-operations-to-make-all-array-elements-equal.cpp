class Solution {
public:
    vector<long long> minOperations(vector<int>& a, vector<int>& q) {
        vector<long long int>v;
        long long int s=0,n=a.size();
        sort(a.begin(),a.end());
       vector<long long> pre(n+2,0);
       // vector<int> minOp(queries.size(),0);
        pre[1]=a[0];
        //use prefix sum and binary search
        for(int i=2;i<=n;i++){
            pre[i]=pre[i-1]+a[i-1];//prefix sum
        }
        for(int i=0;i<q.size();i++){
            auto it=upper_bound(a.begin(),a.end(),q[i])-a.begin();
         //   cout<<it<<endl;
            long long int l=abs(pre[it]-(long long int)((it)*q[i]));
            long long int r=0;
            if(it<a.size()){
             r=((pre[a.size()]-pre[it])-(long long int)((a.size()-it)*q[i]));
            }
            long long int tot=l+r;
        v.push_back(tot);
        }
            return v;
    }
};