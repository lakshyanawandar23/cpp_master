class Solution {
public:
    int maxSatisfied(vector<int>& c, vector<int>& g, int m) {
        //it is just subarray probelm we need to find subaary of size of minutes 
        int ans=0,i=0,j=0,idx=-1,n=c.size(),sum=0,res=0,a=0;
        while(j<n){
            if(g[j]==1){
                ans+=c[j];
            }
            if((j-i+1)==m){
            if(ans>sum){
                idx=i;
                sum=ans;
            }
            if(g[i]==1) ans-=c[i];
                i++;
            }
            j++;
        }
        // if(idx!=-1){
        // for(int k=idx;k<idx+m;k++){
        //    //cout<<idx<<endl;
        //     a+=c[k];
        // }
        // }
        for(int i=0;i<n;i++){
         if(g[i]==0){
                res+=c[i];
            }
        }
        return res+sum;
    }
};