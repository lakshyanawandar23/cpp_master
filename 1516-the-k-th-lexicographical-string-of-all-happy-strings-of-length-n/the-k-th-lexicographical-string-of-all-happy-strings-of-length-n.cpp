class Solution {
public:
  string ans;
    int cnt;
    void solve(int &n,string s,char p,int i){
        if(i==n){
          //  cout<<s<<endl;
            cnt--;
             if(cnt==0) ans=s;
            return ;
        }
       
      if(p!='a') solve(n,s+'a','a',i+1);
      if(p!='b')  solve(n,s+'b','b',i+1);
       if(p!='c') solve(n,s+'c','c',i+1);
        return ;
    }
    string getHappyString(int n, int k) {
        cnt=k;
        solve(n,"",'d',0);
        return ans;
    }
};