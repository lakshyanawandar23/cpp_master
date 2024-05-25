class Solution {
public:
    void solve(int i,string &res,vector<string>&ans,string &s,vector<string>&w){
        if(i>=s.size()){
            res.pop_back();
                ans.push_back(res);
            return ;
        }
        for(int j=0;j<w.size();j++){
        string r=w[j];
        string p=s.substr(i,w[j].size());
    string t=res;
        if(p==r){
            res+=w[j];
            res+=" ";
        //    cout<<res<<endl;
        solve(i+w[j].size(),res,ans,s,w);
        res=t;
        }
        }
        return ;
    }
    vector<string> wordBreak(string s, vector<string>& w) {
        vector<string>ans;
        string res="";
        solve(0,res,ans,s,w);
        return ans;
    }
};