class Solution {
public:
    void solve(vector<int>&num,vector<vector<int>>&v,vector<int>&temp,int i){
        if(i==num.size()){
            v.push_back(temp);
            return ;
        }
        solve(num,v,temp,i+1);
        temp.push_back(num[i]);
        solve(num,v,temp,i+1);
        temp.pop_back();
        return ;
    }
    vector<vector<int>> subsets(vector<int>& num) {
        vector<vector<int>>v;
        vector<int>temp;
        solve(num,v,temp,0);
        return v;
    }
};