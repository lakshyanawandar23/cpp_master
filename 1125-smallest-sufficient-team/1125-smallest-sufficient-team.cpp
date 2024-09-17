class Solution {
public:
    long long int dp[60][(long long int)1<<16];
    int n;
    vector<int>result;
    map<string,int>mp;
    void solve(int i,int ms,vector<int>&p1,vector<int>&temp){
         if(ms==n) {
         // cout<<"hi"<<endl;
          if(result.size()==0||temp.size()<result.size()) result=temp;
          return ;
      }
        if(i==p1.size()) return ; 
        if(dp[i][ms]!=-1) {
            if(dp[i][ms]<=temp.size()) return ;
        }
      solve(i+1,ms,p1,temp);
   //  long long  int take;
        // for(int j=0;j<p[i].size();j++){
        //    // cout<<mp["java"]<<endl;
        //      if(mp.find(p[i][j])!=mp.end()){
        //          int val=mp[p[i][j]];
        //          cout<<val<<endl;
        //          if((long long int)((val<<1)&ms==0)){
        //      cout<<"hii"<<endl;                     
        //             ms=ms|(1<<val);
        //              cout<<ms<<endl;
        //          }
        //      }
        // 
        temp.push_back(i);
       // cout<<ms<<endl;
        solve(i+1,ms|p1[i],p1,temp);
        temp.pop_back();
         dp[i][ms]=temp.size()!=0?temp.size():-1;
        return ;
    }
    vector<int> smallestSufficientTeam(vector<string>& req, vector<vector<string>>& p) {
        //it is the type of knapsack probelm but we have to track of people right we can maintain set/mask 
    // mask for skills
    // mask for  persons
    // idx --->
        mp.clear();
        n=0;
        for(int i=0;i<req.size();i++) {
        //    cout<<req[i]<<endl;
            mp[req[i]]=i;
         //  cout<<mp[req[i]]<<endl;
           n=n|(1<<i);
        }
        vector<int>p1;
        for(int i=0;i<p.size();i++){
            int a=0;
            for(int j=0;j<p[i].size();j++){
                a=a|(1<<mp[p[i][j]]);
            }
            p1.push_back(a);
        }
     //  cout<<n<<endl;
       memset(dp,-1,sizeof(dp));
        vector<int>temp;
    solve(0,0,p1,temp);
        return result;
    }
};