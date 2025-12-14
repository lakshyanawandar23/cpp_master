class Solution {
public:
    int numberOfWays(string c) {
        int n=c.size();
        long long int cnt=1,mod=1e9+7,s=0,p=0;
        for(int i=0;i<n;i++){
            if(c[i]=='S'){
                s++;
                if(s>2){
                    cout<<p<<endl;
                    cnt=((cnt%mod)*((p+1)%mod))%mod;
                    s-=2;  //it becomes zero there also
                    p=0;
                }

            }
            else  {
             if(s==2)   p++;
            }
        }
        return  s==2?cnt:0;
    }
};