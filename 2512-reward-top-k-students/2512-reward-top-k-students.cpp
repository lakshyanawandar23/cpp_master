class Solution {
public:
  static  bool cmp(pair<int,int>a,pair<int,int>b){
        if(a.first==b.first){
            return a.second<b.second;
        }
        return a.first>b.first;
    }
    vector<int> topStudents(vector<string>& p, vector<string>& neg, vector<string>& r, vector<int>& s, int k) {
        map<string,int>m;
        vector<pair<int,int>>v;
        for(auto it:p){
            m[it]=3;
        }
        for(auto it:neg){
            m[it]=-1;
        }
        for(int i=0;i<r.size();i++){
            int sum=0;
            for(int j=0;j<r[i].size();){
                string res="";
                while(r[i][j]!=' '&&j<r[i].size()){
                    res+=r[i][j];
                    j++;
                }
                j++;
                if(m.find(res)!=m.end()){
                    sum+=m[res];
                }
            }
            v.push_back({sum,s[i]});
        }
        sort(v.begin(),v.end(),cmp);
        vector<int>ans;
        for(int i=0;i<k;i++){
            ans.push_back(v[i].second);
        }
        return ans;
    }
};