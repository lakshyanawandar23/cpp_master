class Solution {
public:
    int minFlips(int a, int b, int c) {
    int i=0;
        vector<int>x(32,0);
        vector<int>y(32,0);
        vector<int>z(32,0);
      while(a>0){
          x[i]=a%2;
          a=a/2;
          i++;
      }
        i=0;
         while(b>0){
          y[i]=b%2;
             b=b/2;
          i++;
      }
        i=0;
         while(c>0){
          z[i]=c%2;
        c=c/2;
          i++;
      }
        int cnt=0;
        for(int i=0;i<32;i++){
            if(z[i]==0){
                cnt+=x[i];
                cnt+=y[i];
            }
            else {
                if(x[i]==0&&y[i]==0){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};