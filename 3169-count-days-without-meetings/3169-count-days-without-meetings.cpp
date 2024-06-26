class Solution {
public:
  static  bool cmp(pair<int,int>a,pair<int,int>b){
        if(a.first==b.first) return a.second<b.second;
        return a.first<b.first;
    }
    int countDays(int d, vector<vector<int>>& s) {
        vector<pair<int,int>>v;
        for(int i=0;i<s.size();i++){
            v.push_back({s[i][0],s[i][1]});
        }
        sort(v.begin(),v.end(),cmp);
        int cnt=(v[0].first-1),prev=v[0].second;
        for(int i=1;i<v.size();i++){
            if(prev<v[i].first){
                cnt+=(v[i].first-prev-1);
                
            }
            prev=max(v[i].second,prev);
        }
        cnt+=(d-prev);
        return cnt;
    }
};