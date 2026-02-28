class Solution {
public:
    int maxGoodNumber(vector<int>& num) {
        int ans=0;
        sort(num.begin(),num.end());
        do{
            int res=0;
            for(int i=0;i<3;i++){
                int digit=log2(num[i])+1;
                  res=(res<<digit)+num[i];
            }
            ans=max(ans,res);
        }while(next_permutation(num.begin(),num.end()));
        return ans;
    }
};