class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& num, int k) {
        int n=num.size();
        sort(num.begin(),num.end());
        long long int median,cnt=0;
        if(n%2==0){
        median=num[n/2];
       num[n/2]=k;

        }
        else {
            median=num[n/2];
            num[n/2]=k;
        }
        if(median==k) return cnt;
        if(median>k){
            cnt+=(median-k);
           // cout<<cnt<<endl;
            for(int i=n/2-1;i>=0;i--){
                if(num[i]>num[i+1]){
                 //  cout<<num[i]<<num[i+1]<<endl;
                  // cout<<num[i]-num[i+1]<<endl;
                    cnt+=(num[i]-num[i+1]);
                    num[i]=num[i+1];
                }
                else {
                    cout<<cnt<<endl;
                    return cnt;
                }
            }
        }
        else {
                 cnt+=abs(median-k);
            for(int i=n/2+1;i<n;i++){
                if(num[i]<num[i-1]){
                    cnt+=(num[i-1]-num[i]);
                    num[i]=num[i-1];
                }
                else {
                    return cnt;
                }
            }
        }
        return cnt;
    }
};