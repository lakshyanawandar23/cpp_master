class Solution {
public:
    string clearStars(string s) {
          map<char,int>mp;
       // set<int>s;
        unordered_map<int,int>m;
        vector<vector<int>>v(26);
          for(int i=0;i<s.size();i++){
              if(s[i]=='*'){
                  for(auto it:mp){
                      mp[it.first]--;
                      int idx=v[it.first-'a'][v[it.first-'a'].size()-1];
                      v[it.first-'a'].pop_back();
                      if(mp[it.first]==0) mp.erase(it.first);
                      m[idx]--;
                      break;
                  }
              }
              else {
                  mp[s[i]]++;
                //  s.insert(i);
                  v[s[i]-'a'].push_back(i);
                  m[i]++;
              }
          }
        string ans;
        for(int i=0;i<s.size();i++){
            if(s[i]!='*'&&mp.find(s[i])!=mp.end()&&m[i]>0){
                ans+=s[i];
                mp[s[i]]--;
                if(mp[s[i]]==0) mp.erase(s[i]);
            }
        }
        return ans;
    }
};