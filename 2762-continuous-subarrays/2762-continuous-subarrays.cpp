class Solution {
public:
    long long continuousSubarrays(vector<int>& num) {
        long long int cnt=0;
        map<int,int>mp;
        int j=0;
        for(int i=0;i<num.size();i++){
             mp[num[i]]++;
         int    mini=mp.begin()->first;
          int   maxi=(--mp.end())->first;
            while((maxi-mini)>2&&j<=i){
                mp[num[j]]--;
                if(mp[num[j]]==0){
                mp.erase(num[j]);
                }
               j++;
                mini=mp.begin()->first;
                maxi=(--mp.end())->first;
            }
            if((maxi-mini)<=2) cnt+=(i-j+1);
        }
        return cnt;
    }
};