class Solution { // T.C. O(n) A.S. O(1)
public:
    int climbStairs(int n) {
        if(n==0 || n==1){
            return n;
        }
        int prev=2 , prev2=1;
        for(int i=3;i<=n;i++){
            int curr=prev+prev2;
            prev2=prev;
            prev=curr;
        }
        return prev;
    }
};