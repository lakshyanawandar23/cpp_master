class Solution {
public:
 int cnt;
    bool sorted(vector<int>&num){
        bool flag=true;
        for(int i=1;i<num.size();i++){
            if(num[i]<num[i-1]) {
                flag=false;
                break;
            }
        }
        return flag;
    }
   void shift(vector<int>&num,int &cnt){
        int mini=INT_MAX,idx=-1;
        for(int i=1;i<num.size();i++){
            int sum=num[i]+num[i-1];
            if(sum<mini){
                mini=sum;
                idx=i;
            }
        }
         // shift the order of nums by replacing with sum
         vector<int>ans;
         ans.push_back(num[0]);
         for(int i=1;i<num.size();i++){
            if(i==idx){
               ans.pop_back();
               ans.push_back(mini);
            }
            else ans.push_back(num[i]);
         }
         num=ans;
         cnt++;

   }
    int minimumPairRemoval(vector<int>& num) {
            cnt=0;
   
        if(sorted(num)) return 0;
        while(1){
            shift(num,cnt);
            if(sorted(num)) break;
        }
        return cnt;
    }
};