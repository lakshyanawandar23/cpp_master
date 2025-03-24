class Solution {
public:
bool static cust(pair<int,int>a,pair<int,int>b){
     if(a.first==b.first){
        return a.second<b.second;
     }
     return a.first<b.first;
}
    int countDays(int days, vector<vector<int>>& s) {
        vector<pair<int,int>>v;
          for(int i=0;i<s.size();i++){
            v.push_back({s[i][0],s[i][1]});
          }
        sort(v.begin(),v.end(),cust);
        // for(auto it:v){
        //     cout<<it.first<<" "<<it.second<<endl;
        // }
        int cnt=0,st=v[0].first,e=v[0].second;
        for(int i=1;i<v.size();i++){
           if(v[i].first>e){
            cnt+=(e-st+1);
            st=v[i].first;
            e=v[i].second;
           }
           else {
            e=max(e,v[i].second);
           }
        }
        cnt+=(e-st+1);
        return days-cnt;
    }
};