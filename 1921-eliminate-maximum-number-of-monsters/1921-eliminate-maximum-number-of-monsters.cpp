class Solution {
public:
 static   bool cmp(pair<int,int>&a,pair<int,int>&b){
         if(a.first==b.first){
             return a.second<b.second;
         }
        return a.first<b.first;
    }
    int eliminateMaximum(vector<int>& d, vector<int>& s) {
       vector<int>v;
      for(int i=0;i<d.size();i++){
       v.push_back((ceil)((double)d[i]/s[i]));
      }
        sort(v.begin(),v.end());
        int cnt=1,t=1;
        for(int i=1;i<v.size();i++){
            if((v[i]-t)<=0){
                return cnt;
            }
            else{
                t=t+1;
                cnt++;
            }
            }
        return cnt;
    }
};