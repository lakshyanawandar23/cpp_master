class Solution {
public:
    static bool cmp(pair<int,int>a,pair<int,int>b){
        if(a.second==b.second){
            return a.first<b.first;
        }
        return a.second<b.second;
    }
    int findMinArrowShots(vector<vector<int>>& s) {
        vector<pair<int,int>>v;
        for(int i=0;i<s.size();i++){
            v.push_back({s[i][0],s[i][1]});
        }
        sort(v.begin(),v.end(),cmp);
        int cnt=1,st=0;
        for(int i=1;i<v.size();i++){
             if(v[i].first>v[st].second){
                  cnt++;
                 st=i;
             }
        }
        return cnt;
    }
};