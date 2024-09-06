class Solution {
public:
    vector<int> missingRolls(vector<int>& s, int m, int n) {
        vector<int>v;
        long long int sum=0,rem=0;
        for(auto it:s) sum+=it;
        rem=(m*(n+s.size())-sum);
        if((6*n)<rem) return {};
        int i=0;
        while(i<n){
            int a=rem/(n-i);
           // int carry=rem%(n-i);
            rem=(rem-a);
            if(a>6||a<=0) return {};
            v.push_back(a);
            i++;
        }
        return v;
    }
};