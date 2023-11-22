class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& num) {
        int n=num.size();
        map<int,vector<int>>m;
        for(int i=0;i<n;i++){
            for(int j=0;j<num[i].size();j++){
                m[i+j].push_back(num[i][j]);
            }
        }
        vector<int>ans;
        for(auto it:m){
       //     cout<<it.first<<endl;
           auto p=it.second;
            reverse(p.begin(),p.end());
            for(auto i:p){
              ans.push_back(i);   
            }
        }
        return ans;
    }
};