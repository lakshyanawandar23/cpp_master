class Solution {
public:
 void countchar(vector<int>&v){
    int mod=1e9+7;
    vector<int>temp(26,0);
    for(int i=0;i<25;i++){
        temp[i+1]=v[i];
    }
    temp[0]=(temp[0]+v[25])%mod;
    temp[1]=(temp[1]+v[25])%mod;
    v=temp;
 }
    int lengthAfterTransformations(string s, int t) {
       int n=s.size();
       vector<int>v(26,0);
       for(auto it:s){
        v[it-'a']++;
       }
       while(t--){
          countchar(v);
       }
       int cnt=0,mod=1e9+7;
       for(int i=0;i<26;i++){
        cnt=((cnt%mod)+(v[i]%mod))%mod;
       }
       return cnt;
    }
};