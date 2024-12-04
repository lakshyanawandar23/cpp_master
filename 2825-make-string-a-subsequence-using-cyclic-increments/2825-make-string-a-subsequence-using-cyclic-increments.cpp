class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int i=0,j=0;
        while(j<str2.size()&&i<str1.size()){
            if(str1[i]==str2[j]){
                j++;
            }
           else if(((str1[i]-'a')+1)%26==(str2[j]-'a')){
                j++;
            }
            i++;
        }
        return j==str2.size()?true:false;
    }
};