class Solution {
public:
    bool canMakeEqual(vector<int>& temp, int k) {
        int n=temp.size(),cnt1=0,cnt2=0,t=k;
        vector<int>num=temp;
        for(int i=0;i<n-1;i++){
            if(num[i]==-1){
              num[i]=1;
              num[i+1]*=-1;
              cnt1++;
              t--;
            }
            else {
                cnt1++;
            }
        }
        if(num[n-1]==1&&cnt1==n-1&&t>=0) return true;
        t=k;
        num=temp;
       // cout<<t<<endl;
         for(int i=0;i<n-1;i++){
            cout<<num[i]<<endl;
            if(num[i]==1){
              num[i]=-1;
              num[i+1]=num[i+1]*-1;
              cnt2++;
              t--;
           //   cout<<i<<endl;
            }
            else {
                cnt2++;
            }
        }
         // cout<<t<<endl;
        if(num[n-1]==-1&&cnt2==n-1&&t>=0) return true;
        return false;
    }
};