class Solution {
public:
    int numberOfBeams(vector<string>& v) {
        int n=v.size(),m=v[0].size(),ans=0,prev=0,curr=0,i=0,j;
        for( i=0;i<n;i++){
            for(int k=0;k<m;k++ ){
                if(v[i][k]=='1'){
                    prev++;
                }
            }
            if(prev>0){
           break;
            }
        }
        j=i+1;
        while(j<n){
            for(int k=0;k<m;k++){
                if(v[j][k]=='1'){
                    curr++;
                }
            }
            if(curr>0){
                ans+=(prev*curr);
                prev=curr;
                curr=0;
            }
            j++;
        }
        return ans;
    }
};