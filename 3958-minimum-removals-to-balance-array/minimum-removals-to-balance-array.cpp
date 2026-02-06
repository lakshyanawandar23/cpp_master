class Solution {
public:
    int minRemoval(vector<int>& num, int k) {
        int n=num.size();
        sort(num.begin(),num.end());
        int cnt=0,ans=n-1;
        for(int i=n-1;i>=0;i--){
            int val=ceil(num[i]/(k*1.0));
            // cout<<val<<endl;
            auto idx=lower_bound(num.begin(),num.end(),val)-num.begin();
           // cout<<idx<<endl;
           int res=cnt+idx;
             if(idx<i) ans=min(ans,res);
             cnt++;
        }
        return ans;
    }
};