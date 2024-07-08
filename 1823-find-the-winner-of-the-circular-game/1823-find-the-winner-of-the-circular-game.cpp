class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int>v(n);
        for(int i=0;i<n;i++){
            v[i]=i+1;
        }
        int i=0,tot=n;
        if(k==1) return n;
        while(n>1){
            n--;
          //  cout<<v[i]<<endl;
            int idx=(i+k-1)%v.size();
          //  cout<<v[idx]<<endl;
             i=idx;
            v.erase((v.begin()+idx));
        }
        return v[0];
    }
};