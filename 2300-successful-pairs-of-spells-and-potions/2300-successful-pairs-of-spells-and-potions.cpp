class Solution {
public:
    vector<int> successfulPairs(vector<int>& s, vector<int>& p, long long t) {
        vector<int>v;
        sort(p.begin(),p.end());
        for(int i=0;i<s.size();i++){
            int ans=-1,l=0,h=p.size()-1,m=p.size();
            while(l<=h){
                int m=(l+h)/2;
                long long int r=(long long int )p[m]*(long long int)s[i];
                if((r)>=t){
                    ans=m;
                    h=m-1;
                }
                else{
                    l=m+1;
                }
            }
            if(ans!=-1){
                v.push_back(m-ans);
            }
            else{
                v.push_back(0);
            }
        }
        return v;
    }
};