class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& a, vector<int>& b) {
        vector<int>v;
        unordered_map<int,int>m;
        int cnt=0;
        for(int i=0;i<a.size();i++){
            m[a[i]]++;
            m[b[i]]++;
            if(m[a[i]]==2){
                cnt++;
            }
            if(m[b[i]]==2&&a[i]!=b[i]){
                cnt++;
            }
            v.push_back(cnt);
        }
        return v;
    }
};