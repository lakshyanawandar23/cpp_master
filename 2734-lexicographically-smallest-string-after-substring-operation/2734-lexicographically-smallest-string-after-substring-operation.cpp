class Solution {
public:
    string smallestString(string s) {
        vector<char>v;
        int n=s.size();
        v.push_back('z');
        for(int i=0;i<26;i++){
            v.push_back('a'+i);
        }
        int cnt=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='a'&&cnt==0){
                continue;
            }
            else if(s[i]=='a'&&cnt==1){
                break;
            }
            else{
                s[i]=v[s[i]-'a'];
                cnt=1;
            }
        }
        if(cnt==0){
            s[n-1]=v[s[n-1]-'a'];
        }
        return s;
    }
};