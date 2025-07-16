class Solution {
public:
    int maximumLength(vector<int>& num) {
        int nu=num.size(),e=0,o=0,alt=1,parity=0;
        if(num[0]%2==0) parity=0;
        else parity=1;
        for(auto it:num){
            if(it%2==parity){
                alt++;
                parity^=1;
            }
            if(it%2==0) e++;
            else if(it%2!=0)o++;

        }
        return max({o,e,alt-1});
    }
};