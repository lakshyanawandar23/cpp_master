class Solution {
public:
    int maxSum(vector<int>& num) {
        set<int>s;
        int sum=0,mini=-1e9;
        for(auto it:num){
          if(it>0)  s.insert(it);
          else mini=max(mini,it);
        }
       if(s.size()==0) return mini;
       for(auto it:s){
        sum+=it;
       }
       return sum;
    }
};