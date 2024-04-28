class Solution {
public:
    int minimumAddedInteger(vector<int>& num1, vector<int>& num2) {
        int ans=1e9,n=num1.size();
        sort(num1.begin(),num1.end());
        sort(num2.begin(),num2.end());
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                vector<int>v;
                for(int  k=0;k<n;k++){
                    if(i!=k&&j!=k){
                        v.push_back(num1[k]);
                    }
                }
                int diff=num2[0]-v[0],f=0;
                for(int k=0;k<n-2;k++){
                  if(diff!=(num2[k]-v[k])){
                     f=1;
                      break;
                  }
                }
                if(f==0) ans=min(ans,diff);
            }
        }
        return ans;
    }
};