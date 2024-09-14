class Solution {
public:
    int longestSubarray(vector<int>& num) {
        int ans=0,res=1,cnt=1;
        for(int i=0;i<num.size();i++){
            if(ans<num[i]) {
                ans=num[i];
                cnt=1;
                res=1;
            }
            else if(ans==num[i]){
                cnt++;
                res=max(res,cnt);
            }
            else cnt=0;
        }
        return res;
    }
};