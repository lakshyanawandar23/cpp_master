class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& num) {
        int i=0,j=1;
        while(j<num.size()){
            if(num[j]%2==0&&i!=j){
               swap(num[i],num[j]);
                i++;
            }
            else{
                j++;
            }
        }
        return num;
    }
};