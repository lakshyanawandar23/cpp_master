class Solution {
public:
 bool solve(string s,string &p,int &m,vector<int>&r){
    int i=0,j=0;
  //  cout<<m<<endl;
    for(int i=0;i<=m;i++){
        s[r[i]]='.';
    }
    while(i<s.size()){
        if(p[j]==s[i]&&s[i]!='.') {
            j++;
        }
        i++;
    }
    return j==p.size();
 }
    int maximumRemovals(string s, string p, vector<int>& r) {
        int n=s.size(),l=0,h=r.size()-1,ans=0;
        while(l<=h){
            int mid=(l+h)/2;
            if(solve(s,p,mid,r)){
                ans=max(ans,mid+1);
                l=mid+1;
            }
            else {
                h=mid-1;
            }
        }
        return ans;
    }
};