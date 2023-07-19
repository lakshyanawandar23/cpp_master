class Solution {
public:
    static bool cmp(pair<int,int>&p,pair<int,int>&q){
        return p.second<q.second;
    }
    int eraseOverlapIntervals(vector<vector<int>>& a) {
        vector<pair<int,int>>v;
        for(int i=0;i<a.size();i++){
           v.push_back({a[i][0],a[i][1]});
        }
        sort(v.begin(),v.end(),cmp);
        int cnt=0,prev=INT_MIN;
        for(auto it:v){
            if(it.first<prev){
                cnt++;
            }
            else {
                prev=it.second;
            }
        }
        return cnt;
    }
};