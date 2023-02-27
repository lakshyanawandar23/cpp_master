class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size(),l=0,r;
        if(n%2==0){
            r=n/2;
        }
        else{
            r=n/2+1;
        }
        while(r<n){
            if(2*nums[l]<=nums[r]){
                l++;
            }
            r++;
        }
        return 2*l;
    }
};