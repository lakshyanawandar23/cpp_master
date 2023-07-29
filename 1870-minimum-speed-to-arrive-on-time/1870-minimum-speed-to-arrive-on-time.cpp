class Solution {
public:
    bool solve(vector<int>&dist,double m,double &h){
        double tot=0;
        for(int i=0;i<dist.size();i++){
            tot=ceil(tot);
            tot+=(double)(dist[i]/m);
           // cout<<tot<<endl;
        }
      //  cout<<tot<<" "<<m<<endl;
        return tot<=h;
    }
    int minSpeedOnTime(vector<int>& dist, double h) {
        int ans=INT_MAX;
        int low=1,high=1e7;
        while(low<=high){
            int m=(low+high)/2;
            if(solve(dist,m,h)){
               // cout<<m<<endl;
                ans=m;
                high=m-1;
            }
            else{
                low=m+1;
            }
        }
        if(ans==INT_MAX) return -1;
        return ans;
    }
};