class Solution {
public:
    int minOperations(vector<int>& num) {
        int n=num.size(),cnt=0,flip=0,prev=-1;
        for(int i=0;i<=n-3;i++){
             if(num[i]==0){
                 num[i]^=1;
                 num[i+1]^=1;
                 num[i+2]^=1;
               cnt++;
             }
        }
        for(int i=0;i<n;i++){
            if(num[i]==0) return -1;
        }
        return cnt;
    }
};