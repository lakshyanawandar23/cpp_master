class Solution {
public:
    int pivotInteger(int n) {
        int sum=0;
        for(int i=1;i<=n;i++){
            sum+=i;
            int res=0;
            for(int j=i;j<=n;j++){
                res+=j;
            }
            if(res==sum){
             return i;
            }
        }
        return -1;
    }
};