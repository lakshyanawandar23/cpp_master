class Solution {
public:
    int numSteps(string s) {
        // 101 ->111
        //111 ->  1000
        //1000  -> 1001
        // 1001  -> 1011
        //01 ->
        int cnt=0,n=s.size();
        while(n>1){
            string ans;
            bool flag=true;
         if(s[s.size()-1]=='1'){
              for(int i=s.size()-1;i>=0;i--){
             int sum=(s[i]-'0')^1;
                  if(sum==1){
                      ans='1'+ans;
                      ans=s.substr(0,i)+ans;
                      flag=false;
                      break;
                  }
                  else{
                      ans='0'+ans;
                  }
        }
            if(flag)  ans='1'+ans;
             s=ans;
         }
            else {
                string ans;
                for(int i=1;i<s.size();i++){
       ans+=s[i-1];
                }
                s=ans;
            }
          //cout<<s<<endl;
            n=s.size();
            cnt++;
        }
        return cnt;
    }
};