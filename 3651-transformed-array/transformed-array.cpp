class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& num) {
        int n=num.size();
        vector<int>v(num.size());
        for(int i=0;i<num.size();i++){
            if(num[i]>0){
                v[i]=num[(i+num[i])%n];
            }
            else if(num[i]<0){
                int val=abs(num[i])%n;
                if(i>=val){
                    v[i]=num[i-val];
                }
                else {
                    val=val-i;
                    v[i]=num[n-val];
                }
            }
            else v[i]=num[i];
        }
        return v;
    }
};