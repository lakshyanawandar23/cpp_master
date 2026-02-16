class Solution {
public:
    int reverseBits(int n) {
        string ans;
        while(n){
            ans+=(n%2+'0');
            n=n/2;
        }
      
        int m=ans.size();
        ans.append(32-m+1,'0');
        //  cout<<ans<<endl;
       long  int j=31,res=0;
         for(int i=0;i<ans.size();i++){
                if(ans[i]=='1') res+=pow(2,j);
                j--;
         }
         return res;
    }
};