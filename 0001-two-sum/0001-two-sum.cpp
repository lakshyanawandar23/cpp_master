class Solution {
public:
    vector<int> twoSum(vector<int>& n, int t) {
          map<int,int>m;
        vector<int>v(2,0);
        int cnt=0;
        for(int i=0;i<n.size();++i){
            auto it=m.find(t-n[i]);
          if(it!=m.end()){
             v[0]=i;
              v[1]=m[t-n[i]];
              break;
              }
            else {
                m[n[i]]=i;
                }
         }
        return v;
    }
};