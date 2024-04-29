class Solution {
public:
    int minOperations(vector<int>& num, int k) {
        vector<int>v(32,0);
        vector<int>bit(32,0);
        int i=0;
    while(k>0){
        v[i]+=(k%2);
        k=k/2;
   i++;
    }
        for(int j=0;j<num.size();j++){
       i=0;
            while(num[j]>0){
                bit[i]+=(num[j]%2);
                num[j]/=2;
                i++;
            }
        }
        int cnt=0;
        for(int j=0;j<32;j++){
            if(v[j]){
                if(bit[j]%2==0){
                    cnt++;
                }
            }
            else {
                if(bit[j]%2!=0){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};