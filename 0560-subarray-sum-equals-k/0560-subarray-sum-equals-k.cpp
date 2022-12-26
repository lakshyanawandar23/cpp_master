class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int currSum=0,ans=0;
        for(auto it:nums){
            currSum+=it;
            if(currSum==k){
                ans++;
            }
            if(mp.find(currSum-k)!=mp.end()){
                ans+=mp[currSum-k];
            }
            mp[currSum]++;
        }
        return ans;
    }
};