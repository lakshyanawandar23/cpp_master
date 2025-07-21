class Solution {
public:
    string makeFancyString(string s) {
        stack<char>c;
        for(int i=0;i<s.size();i++){
            if(c.size()>=2&&c.top()==s[i]){
                auto c1=c.top();
                c.pop();
                if(c.top()!=s[i]){
                    c.push(c1);
                    c.push(s[i]);
                }
                else {
                    c.push(c1);
                }
                
            }
            else {
                c.push(s[i]);
            }
        }
        string ans;
        while(!c.empty()){
            ans+=c.top();
            c.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};