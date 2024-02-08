class Solution {
public:
    int minimumOperationsToMakeEqual(int x, int y) {
        if(x<=y) return abs(x-y);
      queue<pair<int,int>>q;
        q.push({x,0});
        set<int>s;
       // s.insert(x);
        while(!q.empty()){
             auto p=q.front();
            q.pop();
            if(s.find(p.first)!=s.end()){
                continue;
            }
            if(p.first==y) return p.second;
            s.insert(p.first);
            if(p.first%11==0){
                q.push({p.first/11,p.second+1});
            }
            if(p.first%5==0){
                q.push({p.first/5,p.second+1});
            }
            q.push({p.first+1,p.second+1});
            q.push({p.first-1,p.second+1});
        }
        return -1;
    }
};