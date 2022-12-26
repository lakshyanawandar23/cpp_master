class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int setbits1=0;
        int setbits2=0;
        int n=num2;
        while(n){
            n=(n & n-1);
            setbits1++;
        }
        n=num1;
        while(n){
            n=(n & n-1);
            setbits2++;
        }
        if(setbits1==setbits2){
            return num1;
        }
        
        n=num1;
        vector<int> binStr(32,0);
        int i=0;
        while(n){
            binStr[i]=n%2;
            n=n/2;
            i++;
        }
        
        long int ans=0;
        for(int j=31;j>=0 && setbits1;j--){
            if(binStr[j]){
                ans+=pow(2,j);
                setbits1--;
            }
        }
        
        
        for(int j=0;j<32 && setbits1;j++){
            if(binStr[j]==0){
                setbits1--;
                ans+=pow(2,j);
                
            }
        }
        
        return ans;
        
    }
};
