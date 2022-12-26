class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long int ans=0;
        long long sum=0;
        unordered_map<int,int> mp;
        int i;
        bool flag=true;
        for(i=0;i<k && i<nums.size();i++){
            mp[nums[i]]++;
            if(mp[nums[i]]>1){
                flag=false;
            }
            sum+=nums[i];
        }
        if(flag){
            ans=sum;
        }
        for(;i<nums.size();i++){
            mp[nums[i]]++;
            mp[nums[i-k]]--;
            if(mp[nums[i-k]]==0){
                mp.erase(nums[i-k]);
            }
            sum+=nums[i];
            sum-=nums[i-k];
            if(mp.size()==k){
                ans=max(sum,ans);
            }
        }
        return ans;
    }
};
