class Solution {
public:
    int chalkReplacer(vector<int>& c, int k) {
     long long int  sum=0,round;
         for(auto it:c){
             sum+=it;
         }
        round=k%sum;
        for(int i=0;i<c.size();i++){
            round-=c[i];
            if(round<0) return i;
        }
        return -1;
    }
};