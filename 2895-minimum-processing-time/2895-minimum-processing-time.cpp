class Solution {
public:
    int minProcessingTime(vector<int>& p, vector<int>& t) {
        int n=p.size();
      sort(p.begin(),p.end());
      sort(t.begin(),t.end(),greater<int>());
        int i=-1,ans=0;
        for(int j=0;j<t.size();j++){
            if(j%4==0){
                i++;
            }
            ans=max(ans,t[j]+p[i]);
        }
        return ans;
    }
};