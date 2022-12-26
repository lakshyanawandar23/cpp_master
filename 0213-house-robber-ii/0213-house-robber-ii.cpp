class Solution { // T.C. O(n) and A.S. O(1)
public:
    int solve(vector<int> & nums){
        int n=nums.size();
        int prev=nums[0];
        int prev2=0;
        for(int i=1;i<n;i++){
            int take=nums[i];
            if(i>1){
                take+=prev2;
            }
            int nottake=prev;
            prev2=prev , prev=max(take,nottake);
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        vector<int> arr1,arr2;
        for(int i=0;i<nums.size();i++){
            if(i!=0){
                arr1.push_back(nums[i]);
            }
            if(i!=nums.size()-1){
                arr2.push_back(nums[i]);
            }
        }
        return max(solve(arr1),solve(arr2));
    }
};
