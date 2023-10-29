class Solution {
public:
    long long minSum(vector<int>& num1, vector<int>& num2) {
        long long int sum1=0,sum2=0,z1=0,z2=0;
        for(auto it:num1){
            sum1+=it;
            if(it==0)  z1++;
        }
        for(auto it:num2){
            sum2+=it;
            if(it==0)  z2++;
        }
        if(sum1+z1>sum2&&z2==0) return -1;
        if(sum2+z2>sum1&&z1==0) return -1;
        return max(sum1+z1,sum2+z2);
    }
};