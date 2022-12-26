class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        dp[nums.size()-1]=0;
        for(int i=nums.size()-2;i>=0;i--){
            
        }
        return solve(nums,0,nums.size()-1,dp);
    }
    
    int solve(vector<int> &nums,int ind,int lastInd,vector<int> &dp){
        
        if(ind==lastInd){
           return 0;
        }
        
        if(dp[ind]!=-1){
            return dp[ind];
        }
        
        int minMoves=10000;
        for(int forward=1;forward<=nums[ind] && forward+ind<=lastInd;forward++){
            minMoves=min(solve(nums,ind+forward,lastInd,dp)+1,minMoves);
        }
        return dp[ind]=minMoves; 
    }
    
};