class Solution {
public:
    void sortColors(vector<int>& num) {
        int  n=num.size(),i=0,j=0,k=num.size()-1;
        while(j<=k){
            if(num[j]==0){
            swap(num[i],num[j]);
                i++;
                j++;
            }
            else if (num[j]==2){
                swap(num[k],num[j]);
                k--;
            }
            else {
                j++;
            }
        }
        return ;
        
    }
};