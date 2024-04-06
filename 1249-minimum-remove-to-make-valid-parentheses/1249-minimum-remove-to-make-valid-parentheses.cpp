class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int>st;
        set<int>p;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push(i);
            }
            else if(s[i]==')'){
                  if(st.empty()){
                    p.insert(i);   
                }
             else{
                    st.pop();
                }
            }
        }
        while(!st.empty()){
            p.insert(st.top());
            st.pop();
        }
        string ans;
        for(int i=0;i<s.size();i++){
            if(p.find(i)==p.end()){
                ans+=s[i];
            }
        }
        return ans;
    }
};