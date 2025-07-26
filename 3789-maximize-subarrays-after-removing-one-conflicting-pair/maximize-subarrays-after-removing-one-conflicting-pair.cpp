class Solution {
public:
    long long maxSubarrays(int n, vector<vector<int>>& v){
           vector<vector<int>>left(n+1);
           vector<long long int>bonus(n+1);
           for(auto it:v){
            int a=min(it[0],it[1]);
            int b=max(it[0],it[1]);
            left[b].push_back(a);
           }
           long long int cnt=0,top1=0,top2=0;
           for(int b=1;b<=n;b++){
            for(auto it:left[b]){
                if(it>top1){
                    top2=top1;
                    top1=it;
                }
                else if(it>top2){
                    top2=it;
                }
            }
                cnt+=(b-top1);
                if(top1>0){
                    bonus[top1]+=(top1-top2);
                }
            
           }
          long long  int mx=0;
           for(auto it:bonus) mx=max(mx,it);
           return cnt+mx;
    }
};