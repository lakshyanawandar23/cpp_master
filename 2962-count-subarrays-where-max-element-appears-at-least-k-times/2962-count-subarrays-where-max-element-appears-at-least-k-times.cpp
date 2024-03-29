class Solution {
public:
    long long countSubarrays(vector<int>& num, int k) {
        long long int cnt=0;
        unordered_map<int,int>mp;
        int i=0,maxi=0,n=num.size();
        for(auto it:num){
            maxi=max(maxi,it);
        }
        for(int j=0;j<num.size();j++){
            if(num[j]==maxi){
            mp[num[j]]++;
            }
            while(i<=j&&mp.find(maxi)!=mp.end()&&mp[maxi]>=k){
                cnt+=(n-j);
                if(num[i]==maxi){
                    mp[num[i]]--;
                }
                i++;
            }
        }
        return cnt;
    }
};