class Solution {
public:
    bool check(string s){
      //  cout<<s<<endl;
        string r=s;
        reverse(s.begin(),s.end());
        return s==r;
    }
    void solve(int i,int prev,string &s,vector<vector<string>>&v,vector<string>ans){
      //  cout<<i<<endl;
        if(i==s.size()-1){
         //   cout<<i<<endl;
            if(check(s.substr(prev))){
                ans.push_back(s.substr(prev));
                v.push_back(ans);
                ans.pop_back();
                //return ;
            }
            return ;
        }
        string res=s.substr(prev,i-prev+1);
       if(check(res)){
          // cout<<res<<endl;
           ans.push_back(res);
           solve(i+1,i+1,s,v,ans);
           ans.pop_back();
       } 
         solve(i+1,prev,s,v,ans);
        return ;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>v;
        vector<string>ans;
        solve(0,0,s,v,ans);
        return v;
    }
};