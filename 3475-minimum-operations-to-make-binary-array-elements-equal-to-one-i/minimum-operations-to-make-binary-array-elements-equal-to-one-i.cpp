class Solution {
public:
    int minOperations(vector<int>& num) {
        int n=num.size(),cnt=0;
        vector<int>op(n,0);
        for(int i=0;i<n-2;i++){
            if(num[i]==1){
                if(op[i]==0) continue;
                else{
                    if(op[i]%2!=0){
                        op[i]+=1;
                        op[i+1]+=1;
                        op[i+2]+=1;
                        cnt++;
                    }
                }
            }
            else{
                if(op[i]%2==0){
                        op[i]+=1;
                        op[i+1]+=1;
                        op[i+2]+=1;
                        cnt++;
                }
            }
        }
        for(int i=0;i<n;i++){
            if(num[i]==1){
                if(op[i]%2!=0){
                    return -1;
                }
            }
            else {
                if(op[i]%2==0){
                    return -1;
                }
            }
        }
   return cnt;
    }
};