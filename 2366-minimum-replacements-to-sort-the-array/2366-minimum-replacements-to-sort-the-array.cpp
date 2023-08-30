class Solution {
public:
    long long minimumReplacement(vector<int>& num) {
        long long int cnt=0,mini=num[num.size()-1];
        for(int i=num.size()-2;i>=0;i--){
              long long int parts=ceil(num[i]/(double)mini);
            cnt+=(parts-1);
            mini=(num[i]/parts);
        }
        return cnt;
    }
};