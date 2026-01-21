class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& num) {
        vector<int>v;
        for(int i=0;i<num.size();i++){
          int x=num[i];
          if(x%2==0) {
            v.push_back(-1);
            continue;
          }
          int t=1;
          while(x&(1<<t)) t++;
          x=(x^(1<<(t-1)));
         v.push_back(x);
        }
        return v;
    }
};

// TC O(N *32);
//SC 0(N);