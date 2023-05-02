class Solution {
public:
    int arraySign(vector<int>& nums) {
        int p=0,n=0,z=0;
        for(auto it:nums){
            if(it>0){
                p++;
            }
            else if(it<0){
                n++;
            }
            else {
                return 0;
            }
        }
        if(n%2!=0) return -1;
        return 1;
    }
};