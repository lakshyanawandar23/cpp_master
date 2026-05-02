class Solution {
public:
    int rotatedDigits(int n) {
        int cnt=0;
        unordered_map<int,int>mp;
        mp[2]=5;
        mp[5]=2;
        mp[6]=9;
        mp[9]=6;
        mp[0]=0;
        mp[1]=1;
        mp[8]=8;
        for(int i=1;i<=n;i++){
            int tmp=i;
            string x;
            bool flag=true;
            while(tmp>0){
                int last=(tmp%10);
               // cout<<last<<endl;
                if(mp.find(last)!=mp.end()){
                    char c='0'+mp[last];
                    x=c+x;   //apppend in front because we are moving backward
                }
                else {
                    flag=false;
                    break;
                }
                tmp=tmp/10;
            }
            if(flag && stoi(x)!=i) cnt++;
        }
        return cnt;
    }
};