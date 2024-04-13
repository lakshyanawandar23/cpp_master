class Solution {
public:
    int trap(vector<int>& h) {
        int sum=0,n=h.size();
        int l[n],r[n];
        l[0]=h[0];
        r[n-1]=h[n-1];
        for(int i=1;i<n;++i){
            l[i]=max(l[i-1],h[i]);
            }
      for(int i=n-2;i>=0;--i){
          r[i]=max(r[i+1],h[i]);
          }
      for(int i=0;i<n;++i){
          sum+=(min(r[i],l[i])-h[i]);
          }
        return sum;
    }
};