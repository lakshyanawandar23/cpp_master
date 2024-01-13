class Solution {
public:
    int minSteps(string s, string t) {
        map<char,int>m;
        map<char,int>n;
        for(auto it:s){
            m[it]++;
        }
        for(auto it:t){
            n[it]++;
        }
        int cnt=0;
        for(auto it:m){
            if(n.find(it.first)==n.end()){
                cnt+=m[it.first];
            }
            else if(n[it.first]-m[it.first]<0){
                cnt+=abs(n[it.first]-m[it.first]);
            }
        }
        return cnt;
    }
};