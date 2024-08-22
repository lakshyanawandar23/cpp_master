class Solution {
public:
    int maxDistance(vector<vector<int>>& v) {
        int mini=v[0][0],maxi=v[0][v[0].size()-1],ans=0,currmax=-1e9,currmini=1e9;
        for(int i=1;i<v.size();i++){
            int n=v[i].size();
            currmax=v[i][n-1];
            currmini=v[i][0];
            cout<<currmini<<" "<<currmax<<" "<<endl;
            ans=max(ans,abs(currmini-maxi));
            ans=max(ans,abs(currmax-mini));
           // ans=max(ans,abs(currmax-currmini));
            mini=min(mini,currmini);
            maxi=max(maxi,currmax);
        }
        return ans;
    }
};