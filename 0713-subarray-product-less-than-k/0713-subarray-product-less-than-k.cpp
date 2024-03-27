class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& num, int k) {
     long long   int p=1;
        int i=0,j=0,cnt=0;
        while(j<num.size()){
            p=p*(num[j]);
            while(i<=j&&p>=k){
                p/=num[i];
                i++;
            }
          //  cout<<i<<" "<<j<<endl;
          cnt+=(j-i+1);
            j++;
        }
        return cnt;
    }
};