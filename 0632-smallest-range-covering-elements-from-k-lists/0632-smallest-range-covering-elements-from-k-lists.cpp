class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& num) {
        vector<pair<int,int>>v;
        for(int i=0;i<num.size();i++){
            for(int j=0;j<num[i].size();j++){
                v.push_back({num[i][j],i});
            }
        }
        sort(v.begin(),v.end());
        unordered_map<int,int>mp;
        int i=0,j=0,s=-1e6,e=1e6;
        while(j<v.size()){
            mp[v[j].second]++;
            while(i<=j&&mp.size()==num.size()){
                mp[v[i].second]--;
                if(mp[v[i].second]==0)  mp.erase(v[i].second);
                if((e-s)>(v[j].first-v[i].first)){
                    s=v[i].first;
                    e=v[j].first;
                  //  cout<<s<<" "<<e<<endl;
                }
                else if((e-s)==(v[i].first-v[j].first)&&s>v[i].first){
                    s=v[i].first;
                    e=v[j].first;
                }
                i++;
            }
            j++;
        }
        return {s,e};
    }
};