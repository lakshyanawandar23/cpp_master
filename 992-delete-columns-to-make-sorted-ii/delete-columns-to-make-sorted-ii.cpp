class Solution {
public:
    int minDeletionSize(vector<string>& s) {
        int n=s.size(),m=s[0].size(),cnt=0;
        vector<int>sorted(n,0);
        for(int i=0;i<m;i++){
            bool bad=true;
            for(int j=1;j<n;j++){
                if(!sorted[j]&&s[j][i]<s[j-1][i]){
                  //  cout<<"hi"<<endl;
                    bad=false;
                    break;
                }
            }
            if(!bad){
                cnt++;
            }
               else {
              for(int j=1;j<n;j++){
                if(s[j][i]>s[j-1][i]){
                    sorted[j]=1;
                }
              }
               }
        }
    return cnt;
    }
};