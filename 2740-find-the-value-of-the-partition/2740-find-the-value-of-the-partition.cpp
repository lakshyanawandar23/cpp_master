class Solution {
public:
    int findValueOfPartition(vector<int>& nums) {
        sort(nums.begin(),nums.end());
         int n=nums.size(),ans=INT_MAX;
        for(int i=1;i<n;i++){
            ans=min(ans,abs(nums[i]-nums[i-1]));
        }
        return ans;
    }
};