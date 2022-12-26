class Solution {
public:
    int maximum69Number (int num) {
        bool flag=true;
        int q=1,rem,n=0;
        while(num){
            rem=num%10;
            n=n*10+rem;
            num/=10;
        }
        while(n){
            rem=n%10;
            if(flag && rem==6){
                num=num*10+9;
                flag=false;
            }
            else{
                num=num*10+rem;
            }
            n/=10;
        }
        return num;
    }
};
