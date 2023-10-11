class Solution {
public:
    bool cmp(vector<int>&a,vector<int>&b){
        if(a[0]==b[0]){
            return a[1]<b[1];
        }
        return a[0]<b[0];
    }
    vector<int> fullBloomFlowers(vector<vector<int>>& f, vector<int>& p) {
        vector<int>s,e;
        for(auto v:f){
            s.push_back(v[0]);
            e.push_back(v[1]);
        }
        sort(s.begin(),s.end());
        sort(e.begin(),e.end());
        vector<int>ans;
        for(int i=0;i<p.size();i++){
         auto j=upper_bound(s.begin(),s.end(),p[i])-s.begin();
         auto k=lower_bound(e.begin(),e.end(),p[i])-e.begin();
            ans.push_back(abs(j-k));
        }
        return ans;
        
    }
};