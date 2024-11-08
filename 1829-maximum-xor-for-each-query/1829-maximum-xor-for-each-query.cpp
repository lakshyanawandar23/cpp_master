class Solution {
public:
    vector<int> getMaximumXor(vector<int>& num, int k) {
        vector<int>v;
        int maxi=0,ans=0,res,i=0;
        res=pow(2,k);
        while(ans<res){
            ans=pow(2,i);
            maxi++;
            i++;
        }
        maxi--;
        vector<int>bit(32,0);
        for(auto it:num){
            int i=0;
            while(it>0){
             bit[i]+=(it%2);
                i++;
                it/=2;
            }  
        }  
        for(int i=num.size()-1;i>=0;i--){
            int j=0,val=0;
            while(j<maxi){
                if(bit[j]%2==0){
                  val+=pow(2,j);  
                }
                j++;
            }
            v.push_back(val);
            j=0;
            while(num[i]>0){
                if(num[i]%2!=0){
                    bit[j]--;
                }
                num[i]/=2;
                j++;
            }
        }
        return v;
    }
};