class Solution {
public:
    int minPairSum(vector<int>& num) {
        int  n=num.size(),ans=0;
        sort(num.begin(),num.end());
        for(int i=0;i<n/2;i++){
            ans=max(ans,num[i]+num[n-i-1]);
        }
        return ans;
    }
};