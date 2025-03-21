class Solution {
public:
    vector<string> findAllRecipes(vector<string>& r, vector<vector<string>>& ing, vector<string>& s) {
        unordered_map<string,int>mp;
        for(auto it:s){
            mp[it]++;
        }
        unordered_set<string>ans;
        bool flag=true;
        int n=mp.size();
        while(flag){
        for(int i=0;i<r.size();i++){
            bool flag1=true;
            for(int j=0;j<ing[i].size();j++){
                if(mp.find(ing[i][j])==mp.end()){
                    flag1=false;
                    break;
                }
            }
            if(flag1){
        mp[r[i]]++;
        ans.insert(r[i]);
            }
        }
      //  n=mp.size();
      cout<<mp.size()<<endl;
          if(n==mp.size()){
            flag=false;
          }
          n=mp.size();
        }
        vector<string>res;
        for(auto it:ans){
            res.push_back(it);
        }
        return  res;
    }
};