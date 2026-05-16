class Solution {
public:
    int findMin(vector<int>& num) {
        int n=num.size(),ans=1e9;
        for(int i=0;i<n;i++){
            ans=min(ans,num[i]);
        }
        return ans;
    }
};