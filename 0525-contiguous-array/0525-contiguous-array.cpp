class Solution {
public:
    int findMaxLength(vector<int>& num) {
        unordered_map<int,int>mp;
        mp[0]=-1;
        int s=0,ans=0;
        for(int i=0;i<num.size();i++){
            if(num[i]==0){
                s+=-1;
            }
            else {
                s+=1;
            }
            if(mp.find(s)!=mp.end()){
                ans=max(ans,(i-mp[s]));
            }
            else {
                mp[s]=i;
            }
        }
        return ans;
    }
};