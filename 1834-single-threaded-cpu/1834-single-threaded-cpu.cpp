class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& t) {
        vector<pair<int,pair<int,int>>>v;
        for(int i=0;i<t.size();i++){
            v.push_back({t[i][0],{t[i][1],i}});
        }
       sort(v.begin(),v.end());
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
      long long  int time=v[0].first,cnt=t.size(),i=0;
        vector<int>ans;
        while(cnt){
             while(i<t.size()&&time>=v[i].first){
                 q.push({v[i].second.first,v[i].second.second});
                 i++;
             }
            if(q.size()>0){
            auto p=q.top();
              //  cout<<p.first<<" "<<p.second<<endl;
                q.pop();
            time+=p.first;
            ans.push_back(p.second);
            cnt--;
            }
            else{
                time=v[i].first;
            }
        }
        return ans;
    }
};