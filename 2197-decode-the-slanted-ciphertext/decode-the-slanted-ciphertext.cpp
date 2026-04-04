class Solution {
public:
    string decodeCiphertext(string s, int r) {
        if(s.size()==0) return s;
        int c=s.size()/r;
        vector<vector<char>>v(r+1,vector<char>(c+1));
        int x=0,y=-1;
        for(int i=0;i<s.size();i++){
           //cout<<s[i]<<endl;
            y=(y+1)%c;
            v[x][y]=s[i];
             if(y==(c-1)){
                x++;
             }
        }
        // for(int i=0;i<r;i++){
        //     for(int j=0;j<c;j++){
        //         cout<<v[i][j]<<endl;
        //     }
        // }
        string ans;
        int i,j=0;
        while(j<c){
          i=0;
          int k=j;
          string res;
          while(i<r&&k<c){
            res+=v[i][k];
            i=i+1;
            k=k+1;
          }
         // cout<<res<<endl;
          j++;
          ans+=res;
        }
        while(ans.back()==' '){
            ans.pop_back();
        }
        return ans;
    }
};