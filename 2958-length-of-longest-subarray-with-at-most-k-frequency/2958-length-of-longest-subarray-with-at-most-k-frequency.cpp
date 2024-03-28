class Solution {
public:
    int maxSubarrayLength(vector<int>& num, int k) {
        unordered_map<int,int>mp;
        int i=0,cnt=0;
        for(int j=0;j<num.size();j++){
            mp[num[j]]++;
            if(mp[num[j]]>k){
            while(i<=j&&mp[num[j]]>k){
                mp[num[i]]--;
                i++;
            }
        }
            cnt=max(cnt,(j-i+1));
    }
        return cnt;
    }
};