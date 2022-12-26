class Solution {
public:   
    int binarySearch(vector<int> &nums,int target){
    int hi=nums.size()-1;
    int lo=0,mid;
        while(hi-lo>1){
            mid=(lo+hi)/2;
            if(nums[mid]<target){
                lo=mid+1;
            }
            else{
                hi=mid;
            }
        }
        if(nums[lo]==target){
            return lo;
        }
        if(nums[hi]==target){
            return hi;
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        return binarySearch(nums,target);
    }
};
