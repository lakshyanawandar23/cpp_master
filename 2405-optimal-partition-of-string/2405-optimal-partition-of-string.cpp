class Solution {
public:
    int partitionString(string s) {
        int cnt=0;
        map<char,int>m;
        for(int i=0;i<s.size();i++){
            if(m.find(s[i])!=m.end()){
                cnt++;
                for(auto it:m){
                    m.erase(it.first);
                }
            }
            m[s[i]]++;
        }
        cnt++;
        return cnt;
    }
};