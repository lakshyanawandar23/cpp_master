class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& m) {
        int n=m.size();
        vector<vector<int>>v;
    map<int,int>l;
    map<int,int>w;
        for(int i=0;i<n;i++){
            w[m[i][0]]++;
            l[m[i][1]]++;
        }
        vector<int>a,b;
        for(auto it:w){
            if(l.find(it.first)==l.end()){
                a.push_back(it.first);
            }
        }
        for(auto it:l){
            if(it.second==1){
                b.push_back(it.first);
            }
        }
        v.push_back(a);
        v.push_back(b);
        return v;
    }
};