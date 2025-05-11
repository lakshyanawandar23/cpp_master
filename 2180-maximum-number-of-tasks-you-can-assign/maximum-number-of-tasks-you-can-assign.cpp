class Solution {
public:
 bool solve(vector<int>w,vector<int>t,int mid,int p,int s){
    int cnt=0;
    multiset<int>st(w.begin(),w.begin()+mid);
    cout<<mid<<endl;
    for(int i=mid-1;i>=0;i--){
       int req=t[i];
       auto it=prev(st.end());
       if(*it>=req) st.erase(it);
       else if(p<=0) return false;
       else {
        int r=t[i]-s;
        cout<<r<<endl;
        p--;
        auto k=st.lower_bound(r);
        if(k==st.end()) return false;
        st.erase(k);

       }
    }
    return true;
 }
    int maxTaskAssign(vector<int>& t, vector<int>& w, int p, int s) {
        int ans=0,l=0,h=min(t.size(),w.size());
        sort(w.begin(),w.end(),greater<int>());
        sort(t.begin(),t.end());
        while(l<=h){
     int mid=(l+h)/2;
     if(solve(w,t,mid,p,s)){
        ans=mid;
        l=mid+1;
     }
     else {
        h=mid-1;
     }
        }
        return ans;
            }
};