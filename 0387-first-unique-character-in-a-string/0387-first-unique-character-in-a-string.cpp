class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int>m;
        for(auto it:s){
            m[it]++;
        }
        for(auto i=0;i<s.size();i++){
            if(m[s[i]]==1){
                return i;
            }
        }
        return -1;
    }
};