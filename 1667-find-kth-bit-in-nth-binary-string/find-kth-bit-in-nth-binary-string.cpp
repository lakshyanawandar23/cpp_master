class Solution {
public:
 string check(string res){
    reverse(res.begin(),res.end());
    string ans;
    for(int i=0;i<res.size();i++){
        int val=(res[i]-'0')^1;
        ans+=(val+'0');
    }
    return ans;
 }
   string solve(int i){
    if(i==0) return "0";
    string res=solve(i-1);
    return res+"1"+check(res);
   }
    char findKthBit(int n, int k) {
        string ans=solve(n-1);
        return ans[k-1];
    }
};