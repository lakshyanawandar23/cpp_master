class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& l, vector<vector<int>>& f) {
           unordered_set<int>sad;
           for(int i=0;i<f.size();i++){
            unordered_set<int>s;
            int m=l[(f[i][0]-1)].size();
            for(int j=0;j<m;j++){
                s.insert(l[(f[i][0]-1)][j]);
            }
            bool flag=true;
            for(int j=0;j<l[(f[i][1]-1)].size();j++){
                if(s.find(l[(f[i][1]-1)][j])!=s.end()){
                    flag=false;
                }
            }
            if(flag){
                sad.insert(f[i][0]);
                sad.insert(f[i][1]);
            }
           }
             int ans=INT_MIN;
             vector<int>v(n+1,0);
             for(auto it:sad){
                 for(int i=0;i<l[(it-1)].size();i++){
                    cout<<l[(it-1)][i]-1<<endl;
                      v[l[(it-1)][i]-1]++;
                 } 
             }
             for(int i=0;i<v.size();i++){
                ans=max(ans,v[i]);
             }
             return sad.size()-ans;
    }
};