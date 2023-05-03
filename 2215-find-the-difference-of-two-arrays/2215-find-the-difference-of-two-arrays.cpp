class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
           vector<vector<int>>v;
        map<int,int>m;
      for(auto it:nums1){
          m[it]++;
          }
      for(auto val:nums2){
          if(m.find(val)!=m.end()){
             m[val]=0;
              }
          }
        
        vector<int>ans;
        for(auto it:m){
            if(it.second>0){
               ans.push_back( it.first);
             
                }
            }
        v.push_back(ans);
        map<int,int>p;
        for(auto val:nums2){
            p[val]++;}
        for(auto it:nums1){
            if(p.find(it)!=p.end()){
                p[it]=0;}
            }
      vector<int>res;
        for(auto k:p){
            if(k.second>0){
         res.push_back(k.first);
            }
          }
        v.push_back(res);
        return v;
    }
};