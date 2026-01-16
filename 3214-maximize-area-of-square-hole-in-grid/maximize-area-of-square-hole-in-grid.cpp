class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& h, vector<int>& v) {
        sort(h.begin(),h.end());
        sort(v.begin(),v.end());
        int ans=1,res=1,cnt=1;
        for(int i=1;i<h.size();i++){
            if((h[i]-h[i-1])==1){
                cnt++;
            }
            else {
                cnt=1;

            }
            ans=max(ans,cnt);
        }
        cnt=1;
        for(int i=1;i<v.size();i++){
            if((v[i]-v[i-1])==1){
                cnt++;
            }
            else {
                cnt=1;
            }
            res=max(res,cnt);
        }
        int mini=min(res,ans)+1;
       // cout<<mini<<endl;
        return mini*mini;
    }
};