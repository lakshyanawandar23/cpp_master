class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& v) {
        sort(v.begin(),v.end()); //start time sort
        vector<int>ans(n,0);
       priority_queue<int,vector<int>,greater<int>>q;
       priority_queue<pair<long long int,int>,vector<pair<long long int,int>>,greater<pair<long long int,int>>>q2;
       for(int i=0;i<n;i++){
        q.push(i); //for rooms
       } 
        for(int i=0;i<v.size();i++){
             while(!q2.empty()&&q2.top().first<=v[i][0]){
                    q.push(q2.top().second);
                    q2.pop();
                }
            if(!q.empty()){
                auto p=q.top();
              q.pop();
              ans[p]++;
              q2.push({v[i][1],p});
            }
            else {
             long long   int time=q2.top().first;
            
              //  int time2=v[i][0];
               // time=max(time,time2);
            //   //  cout<<time<<endl;
            //     while(!q2.empty()&&q2.top().first<=time){
            //         q.push(q2.top().second);
            //         q2.pop();
            //     }
             auto it=q2.top().second;
             q2.pop();
                q2.push({1LL*(v[i][1]+time-v[i][0]),it});
                ans[it]++;
            }
        }
        int res=-1,maxi=0;
        for(int i=0;i<n;i++){
            cout<<ans[i]<<endl;
            if(maxi<ans[i]){
                res=i;
                maxi=ans[i];
            }
        }
        return res;
    }
};