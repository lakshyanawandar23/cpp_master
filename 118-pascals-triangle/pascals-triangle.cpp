class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            vector<int>v;
            v.push_back(1);
            for(int j=1;j<=i-1;j++){
                int sum=ans[i-1][j]+ans[i-1][j-1];
                v.push_back(sum);
            }
            if(i>0){
            v.push_back(1);
            }
            ans.push_back(v);
        }
        return ans;
    }
};