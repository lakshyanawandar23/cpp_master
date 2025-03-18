class Solution {
public:
    int longestNiceSubarray(vector<int>& num) {
        int n=num.size(),i=0,ans=0;
        vector<int>bit(32,0);
        for(int j=0;j<n;j++){
            bool flag=false;
            int t=num[j],k=0;
            while(t>0){
                bit[k]+=(t%2);
                if(bit[k]>1) flag=true;
                t=t/2;
                k++;
            }
            bool tmp=true;
             if(flag){
                while(i<=j&&tmp){
                    int k=0;
                    while(num[i]>0){
                        bit[k]-=(num[i]%2);
                        k++;
                        num[i]/=2;
                    }
                    i++;
                    bool flag=false;
                    for(int k=0;k<32;k++){
                        if(bit[k]>1) flag=true;
                    }
                    tmp=flag;
                }
             }
             ans=max(ans,(j-i+1));
        }
        return ans;
    }
};