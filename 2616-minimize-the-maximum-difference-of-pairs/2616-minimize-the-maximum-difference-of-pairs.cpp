class Solution {
public:
    bool solve(vector<int>&a,int &p,int &m){
        int cnt=0;
        for(int i=1;i<a.size();i++){
            if(a[i]-a[i-1]<=m){
                cnt++;
                i++;
            }
        }
        return cnt>=p;
    }
    int minimizeMax(vector<int>& a, int p) {
        int ans=0,n=a.size();
        sort(a.begin(),a.end());
        int l=0,h=a[n-1]-a[0];
        while(l<=h){
            int m=(l+h)/2;
            if(solve(a,p,m)){
                ans=m;
                h=m-1;
            }
            else{
                l=m+1;
            }
        }
        return ans;
    }
};