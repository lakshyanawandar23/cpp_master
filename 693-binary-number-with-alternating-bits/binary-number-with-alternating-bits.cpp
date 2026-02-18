class Solution {
public:
    bool hasAlternatingBits(int n) {
        int prev=-1;
        while(n){
            int curr=n%2;
            if(prev==curr) return false;
            prev=curr;
            n=n/2;
        }
        return true;
    }
};