class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<int>s;
         if(k==num.size()) return "0";
        for(int i=0;i<num.size();i++){
        while(!s.empty()&&k>0&&(num[i]-'0')<s.top()){
            s.pop();
            k--;
        }
            s.push(num[i]-'0');
    }
       
        string ans;
        while(!s.empty()&&k>0){
            s.pop();
            k--;
        }
        while(!s.empty()){
            ans+=(s.top()+'0');
        s.pop();
            
        }
        
        reverse(ans.begin(),ans.end());
        int i;
        for( i=0;i<ans.size();i++){
            if(ans[i]!='0') {
                break;}
        }
    string res= ans.substr(i);
        return res.size()==0?"0":res;
        
    }
};