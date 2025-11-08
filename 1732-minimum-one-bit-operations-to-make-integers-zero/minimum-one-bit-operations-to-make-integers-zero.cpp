class Solution {
public:
    int minimumOneBitOperations(int n) {
         int mask=n;
         while(mask){
            mask>>=1;
            n^=mask;
         }
         return n;
    } 
};