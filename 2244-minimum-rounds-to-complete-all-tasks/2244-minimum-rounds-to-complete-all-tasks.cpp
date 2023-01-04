class Solution {
public:
    int minimumRounds(vector<int>& t) {
        unordered_map<int,int>m;
        for(auto v:t){
            m[v]++;
        }
        int cnt=0;
        for(auto it:m){
            if(it.second==1){
                return -1;
            }
            else{
                if(it.second%3==0){
                    cnt+=(it.second/3);
                }
                else{
                    cnt+=(it.second/3+1);
                }
            }
        }
        return cnt;
    }
};