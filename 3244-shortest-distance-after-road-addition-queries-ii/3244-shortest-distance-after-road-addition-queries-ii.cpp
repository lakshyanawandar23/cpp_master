class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& q) {
          set<int>s;
        for(int i=0;i<n;i++) s.insert(i);
        vector<int>ans;
        for(auto it:q){
          //  cout<<s.size()<<endl;
            auto i=s.lower_bound(it[0]+1);
            auto j=s.lower_bound(it[1]);
            //cout<<*i<<endl;
            // cout<<*j<<endl;
           s.erase(i,j);
        //   cout<<s.size()<<endl;
            ans.push_back(s.size()-1);
        }
        return ans;
    }
};