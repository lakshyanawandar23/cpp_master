class Solution {
public:
    long long minOperations(vector<int>& s, vector<int>& t, int k) {
        if(k==0){
            for(int i=0;i<s.size();i++){
              if(s[i]!=t[i]){
                  return -1;
              }
            }
            return 0;
        }
        long long int sum=0,cnt=0;
        for(int i=0;i<s.size();i++){
            if((abs(s[i]-t[i]))%k==0){
                cnt+=(abs(s[i]-t[i])/k);
                sum+=(s[i]-t[i]);
            }
            else{
                return -1;
            }
        }
        if(sum!=0){
            return -1;
        }
        return cnt/2;
    }
};