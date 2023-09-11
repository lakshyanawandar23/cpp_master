class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& g) {
        int n=g.size();
        vector<vector<int>>ans;
        int i=0;
        vector<pair<int,int>>s;
        for(int i=0;i<n;i++){
            s.push_back({g[i],i});
      }
        sort(s.begin(),s.end());
        for(int j=0;j<n;){
            int m=s[i].first;
            vector<int>v;
            while((j-i+1)<=m){
                v.push_back(s[j].second);
                j++;
            }
            ans.push_back(v);
            i=j;
        }
        return ans;
    }
};