class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& s, int k) {
        vector<pair<int,int>>v;
        for(int i=0;i<s.size();i++){
            v.push_back({s[i][k],i});
        }
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        vector<vector<int>>ans(s.size(),vector<int>(s[0].size()));
        for(int i=0;i<v.size();i++){
            int r=v[i].second;
            for(int j=0;j<s[r].size();j++){
                ans[i][j]=s[r][j];
            }
        }
        return ans;
    }
};