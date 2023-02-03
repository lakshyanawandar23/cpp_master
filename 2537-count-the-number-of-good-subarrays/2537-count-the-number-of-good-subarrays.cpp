class Solution {
public:
    long long countGood(vector<int>& a, int k) {
        unordered_map<int,int>m;
        long long int i=0,cnt=0,res=0;
        for(int j=0;j<a.size();j++){
           m[a[j]]++;
            res+=(m[a[j]]-1);
            while(res>=k&&i<=j){
                cnt+=(a.size()-j);
                m[a[i]]--;
                res-=m[a[i]];
                if(m[a[i]]==0){
                    m.erase(m[a[i]]);
                }
                i++;
            }
        }
        return cnt;
    }
};