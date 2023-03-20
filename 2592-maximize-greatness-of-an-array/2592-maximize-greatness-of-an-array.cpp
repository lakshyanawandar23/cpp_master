class Solution {
public:
    int maximizeGreatness(vector<int>& num) {
        sort(num.begin(),num.end());
        int i=0,j=1,cnt=0,n=num.size();
        while(j<n){
            if(num[i]<num[j]){
                i++;
                j++;
                cnt++;
            }
            else{
                j++;
            }
        }
        
        return cnt;
    }
};