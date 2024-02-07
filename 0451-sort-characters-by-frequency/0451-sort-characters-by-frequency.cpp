class Solution {
public:
  static  bool cmp(pair<int,int>a,pair<int,int>b){
        return a.second>=b.second;
    }
    string frequencySort(string s) {
   vector<pair<int,char>>v;
        map<char,int>m;
        for(int i=0;i<s.size();i++){
        m[s[i]]++;
        }
        for(auto it:m){
            v.push_back({it.second,it.first});
        }
        sort(v.begin(),v.end());
        string ans;
        for(auto it:v){
        string t;
            t.append(it.first,it.second);
         ans+=t;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};