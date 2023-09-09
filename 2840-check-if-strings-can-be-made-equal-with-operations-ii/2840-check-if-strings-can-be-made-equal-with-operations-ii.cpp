class Solution {
public:
    bool checkStrings(string s1, string s2) {
       unordered_map<char,int>e1,e2,o1,o2;
        if(s1.size()!=s2.size()) return false;
        for(int i=0;i<s1.size();i++){
             if(i%2==0)   {
                 e1[s1[i]]++;
                 e2[s2[i]]++;
             }
            else{
                o1[s1[i]]++;
                o2[s2[i]]++;
            }
        }
        return e1==e2&&o1==o2;
    }
};