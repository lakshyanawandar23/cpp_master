class Solution {
public:
    static bool cmp(pair<int,int>a,pair<int,int>b){
        if(a.second==b.second) return a.first<b.first;
        return a.second<b.second;
    }
    int findMinArrowShots(vector<vector<int>>& p) {
        int n=p.size();
        vector<pair<int,int>>v;
        for(auto it:p){
            v.push_back({it[0],it[1]});
        }
        sort(v.begin(),v.end(),cmp);
        int cnt=1,prev=v[0].second;
        for(int i=1;i<n;i++){
            if(prev<v[i].first){
                cnt++;
                prev=v[i].second;
            }
        }
        return cnt;
    }
};