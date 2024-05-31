class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& q) {
        set<int>s;
        map<int,int>mp;
        map<int,int>m;
      vector<int>ans;
        for(auto it:q){
            auto p=s.find(it[0]);
            if(p!=s.end()){
                cout<<*(p)<<endl;
                  mp[m[*(p)]]--;
                if(mp[m[*(p)]]==0) mp.erase(m[*(p)]);
                s.erase(p);
            }
            mp[it[1]]++;
            m[it[0]]=it[1];
            s.insert(it[0]);
            ans.push_back(mp.size());
        }
        return ans;
    }
};