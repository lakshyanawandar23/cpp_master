class Solution {
public:
      static bool cmp(vector<int>&a,vector<int>&b){
        if(a[0]==b[0]) return a[1]>b[1];
        return a[0]<b[0];
     }
    int maxRemoval(vector<int>& num, vector<vector<int>>& q) {
        int n=num.size();
        sort(q.begin(),q.end(),cmp);
        priority_queue<int>p;
        vector<int>freq(n+1,0);
        int cnt=0,j=0;
        for(int i=0;i<n;i++){
         cnt+=freq[i];
         while(j<q.size()&&q[j][0]<=i){
    p.push(q[j][1]);
    j++;
         }
         while(cnt<num[i]&&!p.empty()&&p.top()>=i){
          freq[p.top()+1]--;
          p.pop();
          cnt++;
         }
         if(cnt<num[i]) return -1;
        }
        return p.size();
    }
};