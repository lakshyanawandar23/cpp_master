class Solution {
public:
    int openLock(vector<string>&s, string t) {
        unordered_map<string,int>m1;
        unordered_map<string,int>m2;
        for(auto it:s){
            m1[it]++;
        }
        queue<pair<string,int>>q;
        q.push({"0000",0});
        if(m1.find("0000")!=m1.end()) return -1;
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            string c=p.first;
            if(c==t) return p.second;
            for(int i=0;i<4;i++){
                int num1=((c[i]-'0')+1)%10;
                int num2=((c[i]-'0')-1)==-1?9:((c[i]-'0')-1)%10;
                string a=c;
                a[i]=num1+'0';
                string b=c;
                b[i]=num2+'0';
                if(m2.find(a)==m2.end()&&m1.find(a)==m1.end()){
                    q.push({a,p.second+1});
                    m2[a]++;
                }
                  if(m2.find(b)==m2.end()&&m1.find(b)==m1.end()){
                      q.push({b,p.second+1});
                      m2[b]++;
                  }
            }
        }
        return -1;
        
    }
};