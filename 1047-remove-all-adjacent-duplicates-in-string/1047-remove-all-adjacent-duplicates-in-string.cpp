class Solution {
public:
    string removeDuplicates(string s) {
        string str="";
        stack<char> stk;
        if(s.length()==0){
            return str;
        }
        for(int i=0;i<s.size();i++){
            bool flag=true;
            while(stk.empty()==false && stk.top()==s[i]){
                stk.pop();
                flag=false;
            }
            if(flag){
                stk.push(s[i]);
            }
        }
        while(stk.empty()==false){
            str+=stk.top();
            stk.pop();
        }
        reverse(str.begin(),str.end());
        return str;
    }
};
