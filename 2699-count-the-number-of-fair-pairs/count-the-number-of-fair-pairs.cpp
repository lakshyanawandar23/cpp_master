class Solution {
public:
    long long countFairPairs(vector<int>& num, int l, int u) {
        int n=num.size();
        long long int cnt=0;
        sort(num.begin(),num.end());
        for(int i=1;i<n;i++){
            auto x=lower_bound(num.begin(),num.begin()+i,l-num[i])-num.begin();
            auto y=upper_bound(num.begin(),num.begin()+i,u-num[i])-num.begin();
            cnt+=(y-x);
           // cout<<x<<" "<<y<<endl;
        }
        return cnt;
    }
};