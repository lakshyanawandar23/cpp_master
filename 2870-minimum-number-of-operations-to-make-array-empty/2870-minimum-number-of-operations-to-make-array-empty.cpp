class Solution {
public:
    int minOperations(vector<int>& num) {
        unordered_map<int,int>m;
        for(auto it:num){
            m[it]++;
        }
        int cnt=0;
        for(auto it:m){
            if(it.second==1) return -1;
           else  if(it.second%3==0){
              cnt+=(it.second/3);
            }
            else if(it.second%3==1){
                cnt+=((it.second-4)/3+2);
            }
            else {
                cnt+=(it.second/3+1);
            }
        }
        return cnt;
    }
};