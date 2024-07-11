class Solution {
public:
    string reverseParentheses(string s) {
        stack<pair<char,int>>st;
        string ans;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                if(ans.size()>0)
                st.push({'(',ans.size()});
                else st.push({'(',0});
            }
            else if(s[i]==')'){
                auto it=st.top();
                st.pop();
                string res=ans.substr(it.second);
                reverse(res.begin(),res.end());
                ans.erase(it.second);
                ans+=res;
            }
            else {
                ans+=s[i];
            }
        }
        return ans;
    }
};