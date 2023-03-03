class Solution {
public:
    int strStr(string s, string t) {
        int j=0,ans=-1,n=s.size(),m=t.size();
        for(int i=0;i<n;){
            if(s[i]==t[j]){
                int k=i;
                while(k<n&&j<m&&s[k]==t[j]){
                    j++;
                    k++;
                }
                if(j==m){
                    ans=i;
                    break;
                }
            }
            i++;
            j=0;
            }
        return ans;
    }
};