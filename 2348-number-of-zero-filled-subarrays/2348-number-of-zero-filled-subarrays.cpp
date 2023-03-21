class Solution {
public:
    long long zeroFilledSubarray(vector<int>& num) {
        long long int cnt=0,ans=0;
        for(int i=0;i<num.size();i++){
            if(num[i]==0){
                cnt++;
                ans+=cnt;
            }
            else{
                cnt=0;
            }
        }
        return ans;
    }
};