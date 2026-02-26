class Solution {
public:
    int numSteps(string s) {
        int cnt=0,n=s.size();
        while(n>1){
            string ans;
            if(s[n-1]=='1'){
                bool flag=true;
                for(int i=n-1;i>=0;i--){
                     if(s[i]=='1'&&flag){
                        ans='0'+ans;
                     }
                     else if(s[i]=='0'&&flag){
                        ans='1'+ans;
                        flag=false;
                     }
                     else {
                        ans=s[i]+ans;
                     }
                }
                if(flag){
                    ans='1'+ans;
                }
            }
            else{
                ans=s.substr(0,n-1);
                s=ans;
            }
            s=ans;
             // cout<<s<<endl;
            n=s.size();
            cnt++;
        }
        return cnt;
    }
};