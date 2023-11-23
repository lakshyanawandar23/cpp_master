class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& num, vector<int>& l, vector<int>& r) {
        int n=num.size(),m=l.size();
        vector<bool>ans;
        for(int i=0;i<m;i++){
            vector<int>v;
            for(int k=l[i];k<=r[i];k++){
                v.push_back(num[k]);
            }
            sort(v.begin(),v.end());
            int diff=v[1]-v[0];
            bool flag=true;
            for(int j=2;j<v.size();j++){
                if(v[j]-v[j-1]!=diff)  {
                    flag=false;
                    break;
                }
            }
            ans.push_back(flag);
        }
        return ans;
    }
};