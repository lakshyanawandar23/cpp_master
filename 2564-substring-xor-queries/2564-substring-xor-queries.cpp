class Solution {
public:
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& q) {
        unordered_map<int,vector<int>>m;
        int n=s.size();
        for(int i=0;i<s.size();i++){
            if(s[i]=='0'){
                if(m.find(0)==m.end()){
                    m[0]={i,i};
                }
                continue;
            }
            long long   int num=0;
            for(int j=i;j<=min(n-1,i+31);j++){
      num = (num << 1) + (s[j] - '0');
                    if(m.find(num)==m.end()){
                    m[num]={i,j};}
            }
        }
        vector<vector<int>>v;
        vector<int>res(2,-1);
        for(auto val:q){
            int r=val[0]^val[1];
            if(m.find(r)!=m.end()){
                v.push_back(m[r]);
            }
            else{
                v.push_back(res);
            }
        }
        return v;
    }
};