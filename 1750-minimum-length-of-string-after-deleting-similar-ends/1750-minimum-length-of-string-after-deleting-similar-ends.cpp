class Solution {
public:
    int minimumLength(string s) {
        int i=0,j=s.size()-1;
        while(i<j){
            if(s[i]==s[j]){
                while(i<s.size()&&s[i]==s[i+1]){
                    i++;
                }
                while(j>0&&s[j]==s[j-1]){
                    j--;
                }
                i++;
                j--;
            }
            else {
                break;
            }
        }
        if(i>j) return 0;
        return (j-i)+1;
    }
};