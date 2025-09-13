class Solution {
public:
    bool doesAliceWin(string s) {
        int n=s.size(),odd=0,even=0,cnt=0;
        for(int i=0;i<n;i++){
            if(s[i]=='a'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='e'){
                cnt++;   //substring of vowel continue that part
            }
            
        }
  return    cnt==0?false:true;
    }
};