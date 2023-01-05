class Solution {
public:
    vector<int> majorityElement(vector<int>& a) {
        vector<int>v;
        sort(a.begin(),a.end());
        int cnt=1,m=a.size()/3;
        for(int i=1;i<a.size();i++){
            if(a[i]!=a[i-1]){
                if(cnt>m){
                    v.push_back(a[i-1]);
                }
                cnt=1;
            }
            else{
                cnt++;
            }
        }
        if(cnt>m){
            v.push_back(a[a.size()-1]);
        }
        return v;
    }
};