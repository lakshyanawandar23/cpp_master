class Solution {
public:
    int rangeBitwiseAnd(int l, int r) {
        int s=0;
        while(l<r){
            l=l>>1;
            r=r>>1;
            s++;
        }
        return l<<s;
    }
};