class Solution {
public:
    int minimumDistance(vector<int>& num) {
         int n=num.size(),ans=INT_MAX;
      //  unordered_map<int,int>mp1;
        unordered_map<int,vector<int>>mp2;
        for(int i=0;i<n;i++){
          //  mp1[num[i]]++;
         
            if(mp2[num[i]].size()==2){
                auto it=mp2[num[i]];
                int f=it[0];
                int s=it[1];
                int dist=abs(f-s)+abs(s-i)+abs(i-f);
                ans=min(ans,dist);
                mp2[num[i]][0]=s;
                mp2[num[i]][1]=i;
            }
            else {
                   mp2[num[i]].push_back(i);
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};