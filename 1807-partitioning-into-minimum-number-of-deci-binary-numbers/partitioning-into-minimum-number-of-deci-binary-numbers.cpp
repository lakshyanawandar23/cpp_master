class Solution {
public:
    int minPartitions(string n) {
        int ans=0;
        for(auto it:n){
            ans=max(ans,it-'0');
        }
        return ans;
    }
};