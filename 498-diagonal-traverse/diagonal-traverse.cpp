class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size(),cnt=0;
        vector<int>ans;
        for(int i=0;i<m;i++){
            vector<int>v;
           int x=0;
           int y=i;
           while(x<n&&y>=0){
            v.push_back(mat[x][y]);
            x=x+1;
            y=y-1;
         
           }
           if(cnt%2){
             for(int j=0;j<v.size();j++){
                  ans.push_back(v[j]);
             }

           }
           else {
            reverse(v.begin(),v.end());
              for(int j=0;j<v.size();j++){
                  ans.push_back(v[j]);
             }
           }
           cnt++;
        }
        for(int i=1;i<n;i++){
                vector<int>v;
           int x=i;
           int y=m-1;
           while(x<n&&y>=0){
            v.push_back(mat[x][y]);
            x=x+1;
            y=y-1;
         
           }
           if(cnt%2){
             for(int j=0;j<v.size();j++){
                  ans.push_back(v[j]);
             }

           }
           else {
            reverse(v.begin(),v.end());
              for(int j=0;j<v.size();j++){
                  ans.push_back(v[j]);
             }
           }
           cnt++;
        }
        return ans;
    }
};