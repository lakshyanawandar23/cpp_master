class Solution {
public:
    bool solve(int &mid,vector<int>&v,int m){
        int p=v[0],i=1;
        m--;
        while(i<v.size()&&m>0){
            if(v[i]-p>=mid){
                p=v[i];
                m--;
            }
            i++;
        }
        if(m==0) return true;
        return false;
    }
    int maxDistance(vector<int>& v, int m) {
        int n=v.size();
        sort(v.begin(),v.end());
        int l=1,h=v[n-1]-v[0],ans=0;
        while(l<=h){
            int mid=(l+h)/2;
            if(solve(mid,v,m)){
                ans=mid;
               l=mid+1;
            }
            else {
                h=mid-1;
            }
        }
        return ans;
    }
};