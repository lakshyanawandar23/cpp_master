class Solution {
public:
    int minimumCost(int m, int n, vector<int>& h, vector<int>& v) {
        int ans=0,ver=0,hor=0, i=0,j=0;
        sort(h.begin(),h.end(),greater<int>());
        sort(v.begin(),v.end(),greater<int>());
        while(i<m-1&&j<n-1){
           // cout<<ans<<endl;
        if(h[i]>=v[j]){
            ans+=((ver+1)*h[i]);
            hor++;
            i++;
        }
            else {
                ans+=((hor+1)*v[j]);
                ver++;
                j++;
            }
        }
        while(i<m-1){
           // cout<<ans<<endl;
            ans+=((ver+1)*h[i]);
            hor++;
            i++;
        }
        while(j<n-1){
         //   cout<<ans<<endl;
             ans+=((hor+1)*v[j]);
                ver++;
                j++;
        }
    return ans;
}
};
