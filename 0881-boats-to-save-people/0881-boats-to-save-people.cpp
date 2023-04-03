class Solution {
public:
    int numRescueBoats(vector<int>& p, int l) {
        sort(p.begin(),p.end());
        int i=0,j=p.size()-1,cnt=0;
        while(i<=j){
            if(p[i]+p[j]>l){
                j--;
                cnt++;
            }
            else{
                i++;
                j--;
                cnt++;
            }
        }
        return cnt;
    }
};