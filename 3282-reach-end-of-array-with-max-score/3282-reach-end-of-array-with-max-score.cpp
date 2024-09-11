class Solution {
public:
    long long findMaximumScore(vector<int>& num) {
        long long int cnt=0;
        int p=0,i;
        for( i=1;i<num.size();i++){
            if(num[p]<=num[i]){
                cnt+=(long long int )((long long int)(num[p])*(i-p));
                p=i;
            }
        }
        if(i!=num.size()-1)  cnt+=((num.size()-1)-p)*num[p];
        return cnt;
    }
};