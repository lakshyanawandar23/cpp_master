class Solution {
public:
    bool solve(long long int mid,vector<long long int>&v,int &d){
      long long  int cnt=v.size()/2-1,prev=v[0];
        for(int i=1;i<v.size();i++){
            prev=prev+mid;
            if(prev<=v[i]+d){
                prev=max(v[i],prev);
            }
            else {
                return false;
            }
        }
        return true;
    }
    int maxPossibleScore(vector<int>& s, int d) {
        //sort(s.begin(),s.end());
        vector<long long int>v;
        for(int i=0;i<s.size();i++){
            v.push_back(s[i]);
           // v.push_back(s[i]+d);
        }
       sort(v.begin(),v.end());
     long long   int l=1,h= 2000000000,ans=0;
        while(l<=h){
         long long   int mid=(l+h)/2;
            if(solve(mid,v,d)){
             //  cout<<mid<<endl;
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