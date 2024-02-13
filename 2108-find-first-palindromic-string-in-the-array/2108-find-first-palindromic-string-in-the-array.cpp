class Solution {
public:
    string firstPalindrome(vector<string>& w) {
        string result="";
        for(int i=0;i<w.size();++i){
           string temp=w[i];
     reverse(temp.begin(),temp.end());
            if(w[i]==temp){
                return w[i];
                }
            }
        return result;
    }
};