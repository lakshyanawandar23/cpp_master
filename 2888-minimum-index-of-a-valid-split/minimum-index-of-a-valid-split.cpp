class Solution {
public:
    int minimumIndex(vector<int>& num) {
        int n=num.size(),cnt=1,d=num[0];
        for(int i=1;i<n;i++){
            if(d!=num[i]){
                cnt--;
                if(cnt==0){
                    cnt=1;
                    d=num[i];
                }
            }
            else {
                cnt++;
            }
        }
        cout<<d<<endl;
        vector<int>pre(n,0);
        if(num[0]==d) pre[0]=1;
        for(int i=1;i<n;i++){
            if(num[i]==d){
                pre[i]=pre[i-1]+1;
            }
            else {
                pre[i]=pre[i-1];
            }
        }
        for(int i=0;i<n;i++){
            int n1=i+1;
            int n2=(n-1)-i;
            int cnt1=pre[i];
            int cnt2=pre[n-1]-pre[i];
            if((n1/2)<cnt1&&(n2/2)<cnt2) return i;
        }
        return -1;
    }
};