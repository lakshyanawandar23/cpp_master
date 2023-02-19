class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int i=2,j=n-1;
        return  min({nums[j]-nums[i],nums[n-3]-nums[0],nums[n-2]-nums[1]});
    }
};