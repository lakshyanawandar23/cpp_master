class Solution {
public:
    long long countSubarrays(vector<int>& num, int a, int b) {
        long long int cnt=0;
        int i=-1,mini=-1,maxi=-1;
        for(int j=0;j<num.size();j++){
            if(num[j]<a||num[j]>b) i=j;
            if(a==num[j]){
                mini=j;
            }
            if(b==num[j]){
                maxi=j;
            }
            int t=min(mini,maxi)-i;
            cnt+=max(0,t);
            
        }
        return cnt;
    }
};