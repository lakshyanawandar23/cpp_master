class Solution {
public:
    void solve(int i,set<vector<int>>&s,vector<int>&v,vector<int>&num,int prev){
        if(i==num.size()){
            if(v.size()>=2){
                s.insert(v);
                return ;
            }
            return ;
        }
        solve(i+1,s,v,num,prev);
        if(prev<=num[i]){
            v.push_back(num[i]);
            prev=num[i];
            solve(i+1,s,v,num,prev);
            v.pop_back();
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& num) {
        set<vector<int>>s;
        vector<vector<int>>ans;
        for(int i=0;i<num.size()-1;i++){
                vector<int>v;
            v.push_back(num[i]);
            solve(i+1,s,v,num,num[i]);
        }
        for(auto it:s){
            ans.push_back(it);
        }
        return ans;
    }
};