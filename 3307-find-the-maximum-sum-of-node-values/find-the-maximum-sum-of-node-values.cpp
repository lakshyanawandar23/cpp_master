class Solution {
public:
    long long maximumValueSum(vector<int>& num, int k, vector<vector<int>>& e) {
        long long int sum=0,cnt=0;
        int diff=INT_MAX;
        for(int i=0;i<num.size();i++){
          if((num[i]^k)>num[i]){
            sum+=(num[i]^k);
            cnt++;
          }
          else {
            sum+=num[i];
          }
          diff=min(diff,abs(num[i]-(num[i]^k)));
        }
        if(cnt%2!=0){
            return sum-diff;
        }
        return sum;
    }
};