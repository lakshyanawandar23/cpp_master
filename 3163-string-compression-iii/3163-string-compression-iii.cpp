class Solution {
public:
    string compressedString(string w) {
        int n=w.size(),cnt=1;
        string ans="";
        for(int i=1;i<n;i++){
            if(cnt>=9){
                ans+=(cnt+'0');
                ans+=w[i-1];
                cnt=1;
            }
            else if(w[i]!=w[i-1]){
                ans+=(cnt+'0');
                ans+=w[i-1];
                cnt=1;
            }
            else {
                cnt++;
            }
        }
        if(cnt){
            ans+=(cnt+'0');
            ans+=w[n-1];
        }
        return ans;
    }
};