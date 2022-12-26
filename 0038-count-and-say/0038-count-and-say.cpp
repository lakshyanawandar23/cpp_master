class Solution {
public:
    string countAndSay(int n) {
        vector<string> ans(32,"");
        ans[0]="0";
        ans[1]="1";
        if(n==1){
            return ans[1];
        }
        for(int i=2;i<=31;i++){
            hash(i,ans);
        }
        return ans[n];
    }
    
    void hash(int n,vector<string> &arr){
        string str="";
        string s=arr[n-1];
        int prev=0;
        int len=s.length();
        for(int i=0;i<len;i++){
            if(i<len-1 && s[i]==s[i+1]){
                prev++;
                continue;
            }
            prev++;
            str=str+to_string(prev);
            str+=s[i];
            prev=0;
        }
        arr[n]=str;
        return;
    }
    
};