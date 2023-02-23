class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        int n=s.size();
        set<string>p;
        queue<string>q;
        q.push(s);
      string ans=s;
        p.insert(s);
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            ans=min(ans,it);
            string store=it;
           for(int i=0;i<it.size();i++){
               if(i%2!=0){
                   int r=it[i]-'0';
                   r=(r+a)%10;
                   it[i]=('0'+r);
               }
           }
            if(p.find(it)==p.end()){
                q.push(it);
                p.insert(it);
            }
            it=store;
            string res=it.substr(n-b,n);
            res+=it.substr(0,n-b);
            if(p.find(res)==p.end()){
                q.push(res);
                p.insert(res);
            }
        }
        return ans;
    }
};