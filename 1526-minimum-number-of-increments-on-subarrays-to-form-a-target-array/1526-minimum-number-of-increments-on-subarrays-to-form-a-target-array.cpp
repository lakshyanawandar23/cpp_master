class Solution {
public:
    int minNumberOperations(vector<int>& t) {
        int cnt=1+(t[0]-1);
        for(int i=1;i<t.size();i++){
            if(t[i]>t[i-1]){
                cnt+=(t[i]-t[i-1]);
            }
        }
        return cnt;
    }
};