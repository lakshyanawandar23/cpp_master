class Solution {
public:
    int findJudge(int n, vector<vector<int>>& t) {
      vector<int>a(n,0);
        vector<int>b(n,0);
        for(int i=0;i<t.size();i++){
            a[t[i][1]-1]++;
            b[t[i][0]-1]++;
        }
        for(int i=0;i<n;i++){
            if(a[i]==n-1&&b[i]==0){
                return i+1;
            }
        }
        return -1;
    }
};