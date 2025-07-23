class Solution {
public:
    int maximumGain(string s, int x, int y) {
        stack<char>st;
        int res=0;
        for(int i=0;i<s.size();i++){
            if(!st.empty()&&x>=y&&st.top()=='a'&&s[i]=='b'){
                st.pop();
                res+=x;
            }
           else  if(!st.empty()&&x<=y&&st.top()=='b'&&s[i]=='a'){
                st.pop();
                res+=y;
            }
              else st.push(s[i]);
        }
        s="";
        while(!st.empty()){
            s+=st.top();
            st.pop();
        }
        reverse(s.begin(),s.end());
         for(int i=0;i<s.size();i++){
            if(!st.empty()&&st.top()=='a'&&s[i]=='b'){
                st.pop();
                res+=x;
            }
           else  if(!st.empty()&&st.top()=='b'&&s[i]=='a'){
                st.pop();
                res+=y;
            }
              else st.push(s[i]);
        }
        return res;
    }
};