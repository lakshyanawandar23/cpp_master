class Solution {
public:
    long long maximumHappinessSum(vector<int>& h, int k) {
     long long int cnt=0,i=0;
      sort(h.begin(),h.end(),greater<int>());
        for(i=0;i<h.size()&&k-->0;i++){
            long long int val=(h[i]-(i));
            if(val>0){
                cnt+=val;
            }
        }
        return cnt;
    }
};