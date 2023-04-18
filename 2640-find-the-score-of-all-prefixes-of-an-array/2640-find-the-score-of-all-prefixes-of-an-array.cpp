class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& num) {
        vector<long long int>ans;
         int maxi=0;
        long long int sum=0;
        for(int i=0;i<num.size();i++){
          maxi=max(maxi,num[i]);
        long long int res=(long long int)(maxi+num[i]+sum);
         sum=res;
        ans.push_back(res);
        }
        return ans;
    }
};