class Solution {
public:
    int maxOperations(string s) {
        int ans=0,res=0,cnt=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                cnt++;
            }
            else if(i>0&&s[i-1]=='1'){
                res=cnt;
                ans+=res;
            }
        }
        return ans;
    }
};