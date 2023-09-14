class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        long long int ans=0,sum=0;
        unordered_map<int,int>p;
        int i=0;
        for(int j=0;j<nums.size();j++){
         p[nums[j]]++;
            sum+=nums[j];
            if((j-i+1)==k){
                if(p.size()>=m){
                    ans=max(ans,sum);
                }
                    sum-=nums[i];
                  p[nums[i]]--;
                    if(p[nums[i]]==0){
                        p.erase(nums[i]);
                    }
                    i++;
                }
        }
        return ans;
    }
};