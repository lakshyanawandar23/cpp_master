class Solution {
public:
    int numTeams(vector<int>& rat) {
        int n=rat.size(),ans=0;
        vector<pair<int,int>>l(n);
        vector<pair<int,int>>r(n);
        l[0]={0,0};
        r[n-1]={0,0};
        for(int i=1;i<n;i++)
            {
            int cnt=0,res=0;
               for(int j=0;j<i;j++){
                   if(rat[i]>rat[j]){
                         cnt++;
                   }
                   else {
                       res++;
                   }
               }
         l[i]={cnt,res}; //greater than rating [i]
            }
        for(int i=n-2;i>=0;i--){
            int cnt=0,res=0;
            for(int j=i+1;j<n;j++){
                if(rat[i]<rat[j]){
                    cnt++;
                }
                else {
                    res++;
                }
            }
         r[i]={cnt,res}; //smaller than rating [j]
        }
        for(int i=0;i<n;i++){
           // cout<<r[i].first<<" "<<r[i].second<<endl;
            ans+=((l[i].first*r[i].first)+(l[i].second*r[i].second));
        }
        return ans;
    }
};