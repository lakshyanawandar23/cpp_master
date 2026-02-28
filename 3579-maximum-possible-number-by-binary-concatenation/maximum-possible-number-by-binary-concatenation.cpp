class Solution {
public:
    int maxGoodNumber(vector<int>& num) {
        int f=0;
        vector<string>v;
        for(int i=0;i<num.size();i++){
            string a;
         while(num[i]>0){
             string b=to_string(num[i]%2);
             a=b+a;
             num[i]/=2;
         }
            v.push_back(a);
        }
        sort(v.begin(),v.end());
        do{
        string res;
        for(int i=0;i<v.size();i++){
            //cout<<v[i]<<endl;
            res+=v[i];
        }
        int i=res.size()-1,ans=0,j=0;
        while(i>=0){
            if(res[i]=='1') ans+=pow(2,j);
            i--;
            j++;
        }
           // cout<<ans<<endl;
            f=max(f,ans);
        }while(next_permutation(v.begin(),v.end()));
        return f;
    }
};