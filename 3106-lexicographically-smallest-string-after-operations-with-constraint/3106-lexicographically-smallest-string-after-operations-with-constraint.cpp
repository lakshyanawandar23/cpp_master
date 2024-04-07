class Solution {
public:
    string getSmallestString(string s, int k) {
        if(k==0) return s;
        int i=0;
        string ans;
        while(i<s.size()&&k>0){
            if(s[i]=='a'){
                ans+='a';
                i++;
                continue;
            }
           // cout<<'z'-'a'<<endl;
            int step=min((26-(s[i]-'a')),(s[i]-'a')%26);
              // cout<<step<<endl;
            if(step<=k){
                ans+='a';
                k-=step;
            }
            else{
                int res=(s[i]-'a')-k;
                ans+=('a'+res);
                k=0;
            }
            i++;
        }
        if(i<s.size()){
            ans+=(s.substr(i));
        }
        return ans;
    }
};