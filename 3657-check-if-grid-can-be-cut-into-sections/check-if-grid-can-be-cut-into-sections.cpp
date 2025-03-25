class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rec) {
        vector<pair<int,int>>x;
        vector<pair<int,int>>y;
        for(int i=0;i<rec.size();i++){
            x.push_back({rec[i][0],rec[i][2]}); //vertical
            y.push_back({rec[i][1],rec[i][3]});  //horixontal
        }
        sort(x.begin(),x.end());
        sort(y.begin(),y.end());
        int cnt=0,e=x[0].second,res=0;
        for(int i=1;i<x.size();i++){
            if(e<=x[i].first){
                cnt++;
                e=x[i].second;
            }
            else {
                e=max(e,x[i].second);
            }
        }
        if(cnt>=2) return true;
        e=y[0].second;
        cnt=0;
         for(int i=1;i<y.size();i++){
            if(e<=y[i].first){
                cnt++;
                e=y[i].second;
            }
            else {
                e=max(e,y[i].second);
            }
        }
        if(cnt>=2) return true;
        return false;
    }
};