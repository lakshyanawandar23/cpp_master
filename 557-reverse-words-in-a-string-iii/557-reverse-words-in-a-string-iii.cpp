class Solution {
public:
    string reverseWords(string s) { // O(n^2) A.S. O(1)
        int j=0;
        s+=' ';
        for(int i=0;i<s.length();i++){
            if(s[i]==' ')
            {
              reverse(s.begin()+j,s.begin()+i);
              j=i+1;
            }
        }
        s.pop_back();
        return s;
    }
};
