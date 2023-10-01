class Solution {
public:
    string reverseWords(string s) {
        string ans;
        int i=0;
        while(i<s.size()){
             string res;
            while(i<s.size()&&s[i]!=' '){
                res+=s[i];
             i++;
            }
            reverse(res.begin(),res.end());
            ans=ans+res+' ';
            i++;
            
        }
        ans.pop_back();
        return ans;
    }
};