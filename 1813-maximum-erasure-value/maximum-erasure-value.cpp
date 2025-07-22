class Solution {
public:
    int maximumUniqueSubarray(vector<int>& num) {
        unordered_map<int,int>mp;
        int i=0,j=0,n=num.size(),ans=0,sum=0;
        for(;i<n;i++){
            sum+=num[i];
            mp[num[i]]++;
            while(j<=i&&mp.size()!=(i-j+1)){
                sum-=num[j];
                mp[num[j]]--;
                if(mp[num[j]]==0) mp.erase(num[j]);
                j++;

            }
            ans=max(ans,sum);
        }
        return ans;
    }
};