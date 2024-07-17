class Solution {
public:
  long long  int minimumCost(int m, int n, vector<int>& h, vector<int>& v) {
      long long   int ans=0,ver=0,hor=0, i=0,j=0,mod=1e9+7;
        sort(h.begin(),h.end(),greater<int>());
        sort(v.begin(),v.end(),greater<int>());
        while(i<m-1&&j<n-1){
           // cout<<ans<<endl;
        if(h[i]>=v[j]){
            ans+=((long long int)(ver+1)*h[i]);
            hor++;
            i++;
        }
            else {
                ans+=((long long int)(hor+1)*v[j]);
                ver++;
                j++;
            }
        }
        while(i<m-1){
           // cout<<ans<<endl;
            ans+=((long long int)(ver+1)*h[i]);
            hor++;
            i++;
        }
        while(j<n-1){
         //   cout<<ans<<endl;
             ans+=((long long int)(hor+1)*v[j]);
                ver++;
                j++;
        }
    return ans;
}
};
