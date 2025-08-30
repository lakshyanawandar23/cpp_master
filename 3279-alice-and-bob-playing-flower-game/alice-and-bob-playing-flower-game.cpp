class Solution {
public:
    long long flowerGame(int n, int m) {
        long long int ans=0;
        int x=max(n,m);
       int y=min(n,m);
       long long int o1,o2,e1,e2;
        if(x%2==0){
            o1=x/2;
            e1=x/2;

        }
        else {
            o1=x/2+1;
            e1=x/2;
        }
        if(y%2==0){
            o2=y/2;
            e2=y/2;
        }
        else {
            o2=y/2+1;
            e2=y/2;

        }
        ans+=(o1*e2);
        ans+=(e1*o2);
        return ans;
    }
};