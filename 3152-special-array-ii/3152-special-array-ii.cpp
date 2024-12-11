class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& num, vector<vector<int>>& q) {
        vector<int>ans;
        vector<bool>v;
        ans.push_back(0);
        int cnt=0;
        for(int i=1;i<num.size();i++){
            if((num[i]%2==0)==(num[i-1]%2==0)||(num[i]%2!=0)==(num[i-1]%2!=0)){
                cnt++;
                ans.push_back(cnt);
            }
            else {
                ans.push_back(ans[i-1]);
            }
        }
        for(auto it:q){
            if(abs(ans[it[1]]-ans[it[0]])==0) v.push_back(true);
            else v.push_back(false);
        }
        return v;
    }
};