class Solution {
public:
 bool solve(long long int mid,long long int n,vector<int>&r,int c){
    long long int cnt=0;
    for(auto it:r){
        long long int res=sqrt((mid/it));
        cnt+=res;
    }
    return cnt>=c;
 }
    long long repairCars(vector<int>& r, int c) {
      long long  int n=r.size(),maxi=*(max_element(r.begin(),r.end()));
        long long int l=1,h=maxi*(1LL*c*c),ans=0;
       while(l<=h){
        long long int mid=l+(h-l)/2;
        if(solve(mid,n,r,c)){
            ans=mid;
            h=mid-1;
        }
        else {
            l=mid+1;
        }
       }
       return ans;
    }
};