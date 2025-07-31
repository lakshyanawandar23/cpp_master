class Solution {
public:
    int longestSubarray(vector<int>& num) {
        int n=num.size(),cnt=0,maxi=0,res=0;
         for(auto it:num){
            maxi=max(maxi,it);
         }
         for(int i=0;i<n;i++){
            if(num[i]==maxi){
                cnt++;
                res=max(res,cnt);
            }
            else {
                cnt=0;
            }
         }
         return res;
    }
};