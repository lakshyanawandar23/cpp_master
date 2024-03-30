class Solution {
public:
    int solve(vector<int>&num,int k){
        unordered_map<int,int>mp;
        int cnt=0,i=0;
        for(int j=0;j<num.size();j++){
            mp[num[j]]++;
            while(i<=j&&mp.size()>k){
                mp[num[i]]--;
                if(mp[num[i]]==0){
                    mp.erase(num[i]);
                }
                i++;
            }
            //when map size equal to k you will follow that subarray 
            cnt+=(j-i+1);
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& num, int k) {
        int a= solve(num,k);
        int b=solve(num,k-1);
        return a-b;
    }
};