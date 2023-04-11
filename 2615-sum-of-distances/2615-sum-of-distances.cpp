class Solution {
public:
    vector<long long> distance(vector<int>& a) {
        vector<long long int>ans(a.size(),0);
        map<int,vector<int>>m;
        unordered_map<int,long long int>mp;
        for(int i=0;i<a.size();i++){
            m[a[i]].push_back(i);
            mp[a[i]]+=i;
        }
        for(auto it:m){
            long long int pre=0,cnt=0,n=it.second.size();
      for(auto val:it.second){
          long long int l=abs(val*cnt-pre);
          pre+=val;
          cnt++;
          long long int r=abs(mp[it.first]-pre-val*(n-cnt));
          ans[val]=(l+r);
      }
        }
        return ans;
    }
};