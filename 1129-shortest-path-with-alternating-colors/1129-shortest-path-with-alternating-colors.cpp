class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& r, vector<vector<int>>& b) {
        vector<int>dis(n,INT_MAX);
        queue<pair<int,char>>q;
        q.push({0,'b'});
        q.push({0,'r'});
        vector<vector<pair<int,int>>>red(n),blue(n);
        vector<int>vis1(n,0);
        vector<int>vis2(n,0);
        for(int i=0;i<r.size();i++){
            red[r[i][0]].push_back({r[i][1],'r'});
        }
        for(int i=0;i<b.size();i++){
            blue[b[i][0]].push_back({b[i][1],'b'});
        }
        dis[0]=0;
        vis1[0]=1;
        vis2[0]=1;
        int cnt=1;
        while(!q.empty()){
            int k=q.size();
            while(k--){
                auto x=q.front().first;
                auto y=q.front().second;
                q.pop();
                if(y=='b'){
                for(auto val:red[x]){
                    if(vis1[val.first]==0){
                        vis1[val.first]=1;
                        dis[val.first]=min(dis[val.first],cnt);
                        q.push({val.first,val.second});
                    }
                }
            }
                else{
                 for(auto val:blue[x]){
                    if(vis2[val.first]==0){
                        vis2[val.first]=1;
                         dis[val.first]=min(dis[val.first],cnt);
                        q.push({val.first,val.second});
                    }
                }
            }
        }
            cnt++;
        }
        for(int i=0;i<n;i++){
            if(dis[i]==INT_MAX){
                dis[i]=-1;
            }
        }
        return dis;
    }
};