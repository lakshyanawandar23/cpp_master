class Solution {
public:
    int numberOfSubarrays(vector<int>& num, int k) {
        int n=num.size(),cnt=0,i=0,j=0,o=0;
   unordered_map<int,int>mp;
        mp[0]++;
        while(j<n){
            if(num[j]%2!=0){
                o++;
            }
             if(o>=k){
       cnt+=mp[o-k];
            }
            mp[o]++;
            j++;
        }
        return cnt;
    }
};