class Solution {
public:
    string largestGoodInteger(string num) {
        string ans;
        for(int i=1;i<num.size()-1;i++){
            if(num[i]==num[i-1]&&num[i+1]==num[i]){
                string s;
                  s+=num[i];
                  s+=num[i];
                  s+=num[i];
                  ans=max(ans,s);
            }
        }
        return ans;
    }
};