class Solution {
public:
    vector<int> plusOne(vector<int>& d) {
        int n=d.size(),carry=1;
        vector<int>ans;
        for(int i=n-1;i>=0;i--){
            d[i]+=carry;
            carry=d[i]/10;
             d[i]=(d[i])%10;
          ans.push_back(d[i]);
        }
     if(carry>0)   ans.push_back(carry);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};