class Solution {
public:
    int minDominoRotations(vector<int>& t, vector<int>& b) {
        int n=t.size(),ans=INT_MAX;
        for(int i=1;i<=6;i++){
            int cnt1=0,cnt2=0;
            for(int j=0;j<n;j++){
                if(t[j]!=i){
                    if(b[j]!=i) {
                        cnt1=1e9;
                        break;
                    }
                    else {
                        cnt1++; //swap values
                    }
                }
            }
              for(int j=0;j<n;j++){
                if(b[j]!=i){
                    if(t[j]!=i) {
                        cnt2=1e9;
                        break;
                    }
                    else {
                        cnt2++; //swap values
                    }
                }
            }
          //  cout<<cnt1<<" "<<cnt2<<endl;
             ans=min(ans,min(cnt1,cnt2));
        }
     return ans==1e9?-1:ans;
    }
};