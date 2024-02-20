class Solution {
public:
    int missingNumber(vector<int>& num) {
        int x=0;
        for(int i=1;i<=num.size();i++){
            x^=i;
        }
        for(auto it:num){
            x^=it;
        }
        return x;
    }
};