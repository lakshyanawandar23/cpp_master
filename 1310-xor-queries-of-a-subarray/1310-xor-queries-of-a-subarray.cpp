class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& q) {
        vector<int>pre,ans;
        int x=0;
        for(auto it:arr){
            x=x^it;
            pre.push_back(x);
        }
        for(auto it:q){
            if(it[0]!=0){
            int res=pre[it[1]]^pre[it[0]-1];
            ans.push_back(res);
            }
            else {
                ans.push_back(pre[it[1]]);
            }
        }
        return ans;
    }
};