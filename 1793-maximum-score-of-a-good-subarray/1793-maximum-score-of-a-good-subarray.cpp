class Solution {
public:
    void solve(vector<int>&num,int &k,vector<int>&l){
      //smallest on left
        stack<int>s;
        int j=num.size()-1;
      while(j>=0){
          while(!s.empty()&&num[s.top()]>num[j]){
          l[s.top()]=(j);
              s.pop();
          }
          s.push(j);
          j--;
      }
        while(!s.empty()){
            l[s.top()]=-1;
            s.pop();
        }
    }
       void solve1(vector<int>&num,int &k,vector<int>&r){
      //smallest on right
        stack<int>s;
        int j=0;
      while(j<num.size()){
          while(!s.empty()&&num[s.top()]>num[j]){
          r[s.top()]=(j);
              s.pop();
          }
          s.push(j);
          j++;
      }
        while(!s.empty()){
            r[s.top()]=num.size();
            s.pop();
        }
    }
    int maximumScore(vector<int>& num, int k) {
        int n=num.size();
        vector<int>l(n),r(n);
        solve(num,k,l);
        solve1(num,k,r);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(l[i]<k&&r[i]>k){
                cnt=max(cnt,(r[i]-l[i]-1)*num[i]);
            }
        }
        return cnt;
    }
};