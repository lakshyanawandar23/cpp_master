class Solution {
public:
    bool doesAliceWin(string s) {
        int cnt=0;
        for(auto it:s){
            if(it=='a'||it=='e'||it=='i'||it=='o'||it=='u') cnt++;
        }
        return cnt==0?false:true;
    }
};