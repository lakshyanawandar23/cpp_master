class Solution {
public:
    string simplifyPath(string p) {
        stack<string>s;
        string ans;
        for(int i=0;i<p.size();++i){
            if(p[i]=='/'){
                continue;}
            else {
            string temp;
    while(i<p.size()&&p[i]!='/'){
        temp+=p[i];
        i++;
        }
         if(temp==".."){
             if(!s.empty()){
                 s.pop();
                 }
             }
            else if(temp=="."){
                continue;}
            else {
                s.push(temp);}
            }
}
        while(!s.empty()){
            ans='/'+s.top()+ans;
            s.pop();
        }
        if(ans==""){
            return "/";}
        return ans;
    }
};