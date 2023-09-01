class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>v;
       for(int i=0;i<=n;++i){
         int cnt=0;
           int t=i;
           while(t>0){
               t=t&(t-1);
               cnt++;
               }
         v.push_back(cnt);
           }
        return v;
    }
};