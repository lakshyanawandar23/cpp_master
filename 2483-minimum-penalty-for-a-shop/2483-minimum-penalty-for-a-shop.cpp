class Solution {
public:
    int bestClosingTime(string s) {
        int ans=INT_MAX,cnt=0,res,rem=1e9,tot=0;
        for(auto it:s){
            if(it=='Y'){
                cnt++;
            }
        }
        for(int i=0;i<s.size();i++){
          //  cout<<rem<<endl;
            if((cnt+tot)<rem){
              //  cout<<i<<endl;
                    rem=cnt+tot;
                    ans=i;
                }
            if(s[i]=='Y'){
                cnt--;
            }
            else{
                tot++;
            }
          //  cout<<rem<<endl;
        }
         if((cnt+tot)<rem){
                    rem=cnt;
                    ans=s.size();
                }
        return ans;
    }
};