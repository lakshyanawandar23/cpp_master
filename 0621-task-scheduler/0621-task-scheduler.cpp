class Solution {
public:
    int leastInterval(vector<char>& t, int n) {
        priority_queue<int>q;
        unordered_map<int,int>m;
        for(auto it:t){
            m[it-'a']++;
        }
        for(auto it:m){
            q.push(it.second);
        }
        int cnt=0;
        while(q.size()>0){
            int k=n+1;
            vector<int>v;
            while(k>0&&!q.empty()){
                auto p=q.top();
                q.pop();
                p--;
                if(p>0){
                    v.push_back(p);
                }
                k--;
            }
                    for(auto it:v){
                        q.push(it);
                    }
            if(q.size()==0){
               // cout<<k<<endl;
                cnt+=(n+1-k);
            }
            else{
                cnt+=(n+1);
            }
        }
        return cnt;
    }
};