class Solution {
public:
    static bool cmp(pair<int,int>&a,pair<int,int>&b){
        if(a.first==b.first) return a.second<b.second;
        return a.first<b.first;
    }
    long long findScore(vector<int>& num) {
        long long int ans=0;
        vector<pair<int,int>>v;
        for(int i=0;i<num.size();i++){
            v.push_back({num[i],i});
        }
        sort(v.begin(),v.end(),cmp);
        for(int i=0;i<v.size();i++){
            int idx=v[i].second;
            if(num[v[i].second]>0){
                ans+=v[i].first;
                if((idx-1)>=0) num[idx-1]=-1;
                if((idx+1)<num.size()) num[idx+1]=-1;
            }
        }
        return ans;
    }
};