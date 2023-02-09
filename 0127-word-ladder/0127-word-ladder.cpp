class Solution {
public:
    int ladderLength(string s, string e, vector<string>& b) {
         queue<string>q;
        unordered_set<string>m;
        for(auto v:b){
            m.insert(v);
        }
        q.push(s);
        int cnt=1;
        while(!q.empty()){
            int k=q.size();
            while(k--){
                auto p=q.front();
                q.pop();
                m.erase(p);
                if(p==e){
                    return cnt;
                }
                    for(int i=0;i<p.size();i++){
                        for(char c='a';c<='z';c++){
                        string adj=p;
                        adj[i]=c;
                        if(m.find(adj)!=m.end()){
                      //   cout<<adj<<endl;
                            q.push(adj);
                        }
                    }
                }
            }
            cnt++;
        }
        return 0;
    
    }
};