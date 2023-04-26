class Solution {
public:
    int addDigits(int num) {
        string s=to_string(num);
        while(s.size()>1){
            int i=0,ans=0;
            while(i<s.size()){
                ans+=(s[i]-'0');
                i++;
            }
            s=to_string(ans);
        }
        return stoi(s);
    }
};