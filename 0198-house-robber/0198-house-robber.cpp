class Solution {
public:
    int rob(vector<int>& nums) { // T.C. O(n) and A.S. O(1)
        int n=nums.size();
        int prev=nums[0];
        int prev2=0;
        for(int i=1;i<n;i++){
            int pick=nums[i];
            if(i>1){
                pick+=prev2;
            }
            int notPick=prev;
            prev2=prev , prev=max(pick,notPick);
        }
        return prev;
    }
};