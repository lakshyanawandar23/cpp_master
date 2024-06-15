class Solution {
public:
    static bool cmp(pair<int,int>a,pair<int,int>b){
    if(a.first==b.first) return a.second>b.second;
        return a.first<b.first;
    }
    int findMaximizedCapital(int k, int w, vector<int>& p, vector<int>& c) {
     priority_queue<int>q;
        vector<pair<int,int>>v;
        for(int i=0;i<p.size();i++){
           // q.push({c[i],p[i]});
            v.push_back({c[i],p[i]});
        }
        sort(v.begin(),v.end());
        int cnt=w,i=0,n=v.size();
       while(k--) {
       //   w-=v[i].first;
       //     cout<<cnt<<endl;
           while(i<n&&cnt>=v[i].first){
               q.push(v[i].second);
               i++;
           }
           if(!q.empty()){
           auto it=q.top();
           q.pop();
            cnt+=it;
           }
        }
        // while(k--){
        //     auto it=q.top();
        //     q.pop();
        //     if(w<it.first) return w;
        //     w-=it.first;
        //     w+=it.second;
        // }
        return cnt;
    }
};