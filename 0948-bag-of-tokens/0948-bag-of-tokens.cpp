class Solution {
public:
    int bagOfTokensScore(vector<int>& t, int p) {
        sort(t.begin(),t.end());
        int i=0,j=t.size()-1,cnt=0,ans=0;
        while(i<=j){
            if(t[i]<=p){
                p-=t[i];
                i++;
               cnt++;
            }
            else if(cnt>0){
                cnt--;
                p+=t[j];
                j--;
            }
            else {
                break;
            }
            ans=max(ans,cnt);
        }
        return ans;
    }
};