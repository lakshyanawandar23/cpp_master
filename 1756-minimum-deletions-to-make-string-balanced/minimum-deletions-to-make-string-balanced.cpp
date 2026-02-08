class Solution {
public:
    int minimumDeletions(string s) {
        int cnt=1e9,n=s.size();
      vector<int>a(n,0);
      vector<int>b(n,0);
      int b_count=0,a_count=0;
        for(int i=1;i<s.size();i++){
          //    if(s[i-1]=='b') b_count++;
              b[i]=b[i-1]+(s[i-1]=='b');
        }
        for(int i=n-2;i>=0;i--){
           a[i]=a[i+1]+(s[i+1]=='a');
           // if(s[i+1]=='a') a_count++;
        }
        // for(auto it:b){
        //     cout<<it<<endl;
        // }
        for(int i=0;i<s.size();i++){
            cnt=min(cnt,a[i]+b[i]);
        }
        return cnt;
    }
};