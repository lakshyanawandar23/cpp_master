class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size(),l=0,r;
        r=n%2==0?n/2:n/2+1;
        while(r<n){
            if(2*nums[l]<=nums[r]){
                l++;
            }
            r++;
        }
        return 2*l;
    }
};