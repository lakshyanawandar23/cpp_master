class Solution {
public:
    int findMinDifference(vector<string>& s) {
       // sort(s.begin(),s.end());
        vector<int>v;
        int ans=1e9;
        for(int i=0;i<s.size();i++){
            int h2=stoi(s[i].substr(0,2));
            int m2=stoi(s[i].substr(3));
            cout<<h2<<" "<<m2<<endl;
            int r=(h2*60+m2);
            v.push_back(r);
            cout<<v[i]<<endl;
        }
        sort(v.begin(),v.end());
        for(int i=1;i<v.size();i++) {
            ans=min(ans,(v[i]-v[i-1]));
            
        }
        return min(ans,((24*60-v[v.size()-1])+v[0]));
    }
};