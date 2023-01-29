class Solution {
public:
    void solve(int src,vector<int>&dis,vector<int>&e,vector<int>&vis,int distance){
            if(src!=-1&&vis[src]==0){
                vis[src]=1;
                dis[src]=distance;
                solve(e[src],dis,e,vis,distance+1);
            }
    }
    int closestMeetingNode(vector<int>& e, int node1, int node2) {
        vector<int>dis1(e.size(),-1);
        vector<int>dis2(e.size(),-1);
        vector<int>vis(e.size(),0);
        solve(node1,dis1,e,vis,0);
        vis.assign(e.size(),0);
        solve(node2,dis2,e,vis,0);
        int ans=-1,res=INT_MAX;
        for(int i=0;i<e.size();i++){
         //   cout<<dis1[i]<<" "<<dis2[i]<<endl;
            if(min(dis1[i],dis2[i])>=0&&res>max(dis1[i],dis2[i])){
                res=max(dis1[i],dis2[i]);
              ans=i;
            }
        }
        return ans;
    }
};