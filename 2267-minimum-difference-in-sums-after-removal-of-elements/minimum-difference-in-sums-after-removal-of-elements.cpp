class Solution {
public:
    long long minimumDifference(vector<int>& num) {
       long long int n=num.size()/3;
        long long int sum=0;
        priority_queue<long long int>q;
        priority_queue<long long int,vector<long long int>,greater<long long int>>p;
        vector<long long int>l,r(num.size(),0);
      long long  int left=0,right=0;
        for(long long int i=num.size()-1;i>=n;i--){
             p.push(num[i]);
             right+=num[i];
             while(p.size()>n){
                   right-=p.top();
                   p.pop();

             }
             if(p.size()==n) r[i]=right;

        }
     
     long long int ans=LLONG_MAX;
        for(long long int i=0;i<num.size()-n;i++){
            left+=num[i];
            q.push(num[i]);
            if(q.size()>n){
                left-=q.top();
                q.pop();
            }
           // cout<<left<<endl;
            if(q.size()==n) ans=min(ans,left-r[i+1]);
        }
        return ans;
    }
};