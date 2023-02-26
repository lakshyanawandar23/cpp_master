class Solution {
public:
    vector<int> divisibilityArray(string w, int m) {
        vector<int>ans;
      long long  int s=0;
        for(int i=0;i<w.size();i++){
            s=(s*10+(w[i]-'0'))%m;
            if(s==0){
                ans.push_back(1);
            }
            else{
                ans.push_back(0);
            }
        }
        return ans;
    }
};