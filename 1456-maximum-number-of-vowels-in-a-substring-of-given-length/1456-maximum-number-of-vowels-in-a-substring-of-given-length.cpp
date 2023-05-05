class Solution {
public:
    int maxVowels(string s, int k) {
        int ans=0,cnt=0,j=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='a'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='e'){
                cnt++;
            }
            if(i-j+1==k){
                ans=max(ans,cnt);
                if(s[j]=='a'||s[j]=='i'||s[j]=='o'||s[j]=='e'||s[j]=='u'){
                    cnt--;
                }
                j++;
            }
        }
        return ans;
    }
};