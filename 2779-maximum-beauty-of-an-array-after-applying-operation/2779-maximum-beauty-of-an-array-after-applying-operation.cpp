class Solution {
public:
    int maximumBeauty(vector<int>& num, int k) {
        map<int,int>m;
        for(int i=0;i<num.size();i++){
            m[num[i]-k]++;
            m[num[i]+k+1]--;
        }
        int ans=0,mxans=0;
        for(auto it:m){
            ans+=it.second;
            mxans=max(ans,mxans);
        }
        return mxans;
    }
};