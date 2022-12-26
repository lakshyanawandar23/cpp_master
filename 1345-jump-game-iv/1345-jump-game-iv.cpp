class Solution {
public:
    int minJumps(vector<int>& arr) {
        queue<pair<int,int>>q;
        vector<int>vis(arr.size(),0);
        map<int,vector<int>>m;
        for(int i=0;i<arr.size();i++){
            m[arr[i]].push_back(i);
        }
        q.push({arr[0],0});
        vis[0]=1;
        int cnt=0;
        while(!q.empty()){
            int k=q.size();
            while(k--){
                auto p=q.front();
                q.pop();
                if(arr.size()-1==p.second){
                    return cnt;
                }
                int i=p.second;
                if(i-1>=0&&vis[i-1]==0){
                    vis[i-1]=1;
                    q.push({arr[i-1],i-1});
                }
                if(i+1<arr.size()&&vis[i+1]==0){
                    vis[i+1]=1;
                    q.push({arr[i+1],i+1});
                }
                for(auto val:m[p.first]){
                        if(val!=p.second&&vis[val]==0){
                            vis[val]=1;
                            q.push({p.first,val});
                        }
                    }
                m.erase(p.first);
                }
            cnt++;
        }
        return cnt;
    }
};